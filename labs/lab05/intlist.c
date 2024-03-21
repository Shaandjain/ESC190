#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h"

typedef struct IntArrayList{
    int *data;
    int size;
    int capacity;
}IntArrayList;

//a) memcpy assumes that the source and 
//destination memory blocks do not overlap. 
//If they do overlap, the behavior of memcpy 
//is undefined, which means it could result 
//in data corruption or other unexpected behavior.

// memmove is designed to handle overlapping memory blocks.
// It first makes a temporary copy of the source data, then 
// copies from the temporary location to the destination.



//creates an IntArrayList from an array of integers.
//--It takes a double pointer to an IntArrayList, a pointer to the data array, and the size of the array as parameters.
void create_AL_from_data(IntArrayList **p_AL, int *data, int size){
    // Allocate memory for the IntArrayList struct
    (*p_AL) = (IntArrayList*)malloc(sizeof(IntArrayList));
    // Set the size and capacity of the IntArrayList to the given size
    (*p_AL)->size = size;
    (*p_AL)->capacity = size;
    // Allocate memory for the data array inside the IntArrayList
    (*p_AL)->data = (int*)malloc(size * sizeof(int));

    // Copy the elements from the data array to the IntArrayList's data array
    for (int i = 0; i < size; i++){
        (*p_AL)->data[i] = data[i];
    }
}


void AL_append(IntArrayList *AL, int new_value){
    if (AL->size == AL->capacity){
        AL->capacity *= 2;
        AL->data = (int*)realloc(AL->data, AL->capacity * sizeof(int));
    }
    AL->data[AL->size] = new_value;
    AL->size++;
}

void AL_insert(IntArrayList *AL, int new_value, int index){
    if (AL->size == AL->capacity){
        AL->capacity *= 2;
        AL->data = (int*)realloc(AL->data, AL->capacity * sizeof(int));
    }
    // Shift elements to the right to make space for the new value
    memmove(AL->data + index + 1, AL->data + index, (AL->size - index) * sizeof(int));
    // Insert the new value at the specified index
    AL->data[index] = new_value;
    AL->size++;
}

//function removes an element from the IntArrayList at the specified index.
//take pointer to the IntArrayList and the index of the element to be removed as parameters.
void AL_delete(IntArrayList *AL, int index){
    // Shift elements to the left to overwrite the element at the specified index
    memmove(AL->data + index, AL->data + index + 1, sizeof(int)*(AL->size - index));
    // Decrease the size of the IntArrayList by 1
    AL->size--;
}


void AL_free(IntArrayList *AL){
    // Free the memory allocated for the data array inside the IntArrayList
    free(AL->data);
    // Free the memory allocated for the IntArrayList struct itself
    free(AL);
}

int AL_get(void *list, int index){
    IntArrayList *AL = (IntArrayList*)list;
    return AL->data[index];
}



