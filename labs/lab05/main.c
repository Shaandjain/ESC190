#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist3.c"


void print_list(IntArrayList *AL){
    for (int i = 0; i < AL->size; i++) {
        printf("%d ", AL_get(AL, i));
    }
    printf("\n");
}

int main() {
    IntArrayList *AL;
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    // Test create_AL_from_data
    create_AL_from_data(&AL, data, size);
    print_list(AL);  // Should print: 1 2 3 4 5
    printf("\n");

    // Test AL_append
    AL_append(AL, 6);
    print_list(AL);  // Should print: 1 2 3 4 5 6
    printf("\n");

    // Test AL_insert
    AL_insert(AL, 1, 0);
    print_list(AL);  // Should print: 1 1 2 3 4 5 6
    printf("\n");

    // Test AL_remove
    AL_delete(AL, 3);
    print_list(AL);  // Should print: 1 2 3 4 5 6
    printf("\n");

    // Test AL_free
    AL_free(AL);
    printf("\n");

    

    return 0;
}