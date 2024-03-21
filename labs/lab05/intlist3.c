#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.c"



void increase_capacity(IntArrayList *AL){
    AL->capacity *= 2;
    AL->data = (int*)realloc(AL->data, AL->capacity * sizeof(int));
}

void decrease_capacity(IntArrayList *AL){
    AL->capacity /= 2;
    AL->data = (int*)realloc(AL->data, AL->capacity * sizeof(int));
}

void shift_elems(IntArrayList *AL, int start_index, int shift_amount){
    memmove(AL->data + start_index + shift_amount, AL->data + start_index, (AL->size - start_index) * sizeof(int));
}
