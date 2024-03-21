#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h"

typedef struct IntArrayList{
    int *data;
    int size;
    int capacity;
}IntArrayList;


// Helper function to reallocate memory for the IntArrayList's data array
void AL_resize(IntArrayList *AL, int new_capacity) {
    if (new_capacity != AL->capacity) {
        AL->capacity = new_capacity;
        AL->data = (int*) realloc(AL->data, AL->capacity * sizeof(int));
    }
}

// Helper function to shift elements in the array
void AL_shift_elems(IntArrayList *AL, int start_index, int shift_amount) {
    memmove(AL->data + start_index + shift_amount, AL->data + start_index, (AL->size - start_index) * sizeof(int));
}


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
        AL_resize(AL, AL->capacity * 2);
    }
    AL->data[AL->size] = new_value;
    AL->size++;
}

void AL_insert(IntArrayList *AL, int new_value, int index){
    if (AL->size == AL->capacity){
        AL_resize(AL, AL->capacity * 2);
    }
    AL_shift_elems(AL, index, 1);
    AL->data[index] = new_value;
    AL->size++;
}

void AL_delete(IntArrayList *AL, int index){
    AL_shift_elems(AL, index, -1);
    AL->size--;
    
    if (AL->size <= AL->capacity / 2){
        AL_resize(AL, AL->capacity / 2);
    }
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