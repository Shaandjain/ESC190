#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structs.h"

void LL_append(LL *my_list, int data) {
    // Create a new node
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (my_list->head == NULL) {
        my_list->head = new_node;
    } else {
        // Otherwise, append the new node to the end of the list
        node *cur = my_list->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }

    // Increase the size of the list
    my_list->size++;
}

int validate_list_length(LL *my_list){
    int count = 0;
    //check if the head of the list is null, while it is not null, increment the count and move to the next node
    while (my_list->head != NULL){
        my_list->head = my_list->head->next;
        count++;
    }

    //check the count value, if it is equal to the size of the list, return 1, else return 0
    if (count == my_list->size){
        return 1;
    }
    else{
        return 0;
    }
}


void delete (LL *my_list, int index){
    node *cur = my_list->head;

    // If the index is 0, delete the head node
    if (index == 0){
        my_list->head = cur->next;
        free(cur);
        my_list->size--;
        return;
    }   

    // Traverse the list to find the node at the specified index
    for (int i = 0; cur != NULL && i < index - 1; i++){
        cur = cur->next;
    }

    // If the current node or the next node is NULL, return
    if (cur == NULL || cur->next == NULL){
        return;
    }

    // Delete the node at the specified index
    node *next = cur->next->next;
    free(cur->next);
    cur->next = next;
    my_list->size--;
}

void print_LL(LL *my_list) {
    node *cur = my_list->head;
    while(cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}