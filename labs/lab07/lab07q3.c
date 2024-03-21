#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct
typedef struct circleQueue{
    int *data;     
    int first;     
    int last;      
    int capacity;   
} circleQueue;


void create_cq(circleQueue **p_p_q, int capacity){
    // Allocate memory for the circleQueue struct
    (*p_p_q) = (circleQueue*)malloc(sizeof(circleQueue));
    
    // Allocate memory for the queue data array
    (*p_p_q)->data = (int*)malloc(capacity * sizeof(int));
    
    // Initialize the first and last indices to 0
    (*p_p_q)->first = 0;
    (*p_p_q)->last = 0;
    
    // Set the capacity of the queue
    (*p_p_q)->capacity = capacity;
}

// Function to enqueue 
void enqueue(circleQueue *q, int value) {
    // Check if the queue is full
    if ((q->last + 1) % q->capacity == q->first){
        // Resize handling needs to update capacity
        int newCapacity = q->capacity * 2;
        q->data = (int*)realloc(q->data, newCapacity * sizeof(int));
        if (q->first > q->last) {
            memmove(q->data + q->capacity, q->data, q->last * sizeof(int));
            q->last += q->capacity;
        }
        q->capacity = newCapacity; // Update the capacity after resizing
    }

    q->data[q->last] = value;
    q->last = (q->last + 1) % q->capacity;
}

// Function to dequeue an element from the circular queue
int dequeue(circleQueue *q){
    // Get the index of the first element
    int index = q->first;
    
    // Update the first index to the next position
    q->first = (q->first + 1) % (q->capacity);
    
    // Return the dequeued element
    return q->data[index];
}

void printq(circleQueue q){
    // Iterate over the elements in the queue and print 
    for (int i = q.first; i < q.last; i++){
        printf("%d ", q.data[i]);
    }
    
    printf("\n");
    // Print the index of the first element
    printf("First: %d\n", q.first);
}


int main() {
    circleQueue *cq;
    int capacity = 5; // Initial capacity of the circular queue

    // Create the circular queue
    create_cq(&cq, capacity);

    // Enqueue elements into the circular queue
    for (int i = 1; i <= 7; i++) { // This will trigger a resize
        enqueue(cq, i * 10);
        printf("Enqueued: %d\n", i * 10);
    }

    // Print the queue's contents
    printq(*cq);

    // Dequeue two elements

    printf("Dequeued: %d\n", dequeue(cq));
    printf("Dequeued: %d\n", dequeue(cq));

    // Print the queue again
    printq(*cq);

    // Free allocated memory
    free(cq->data);
    free(cq);

    return 0;
}