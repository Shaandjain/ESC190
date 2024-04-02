#include <stdio.h>
#include <stdlib.h>

// Function to perform breadth-first search
void breadth_first_search(int adjacency_matrix[6][6], int start_node) {
    int visited[6];
    int ds[6]; // queue
    int front = 0;
    int rear = 0;

    ds[rear] = start_node;
    rear++;
    visited[start_node] = 1;

    while (front < rear) {
        int current_node = ds[front];
        printf("%d\n", current_node+1);
        front++;
        for (int i = 0; i < 6; i++) {
            // Check if there is an edge between the current node and the adjacent node
            // and if the adjacent node has not been visited yet
            if (adjacency_matrix[current_node][i] == 1 && visited[i] == 0) {
                ds[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
    printf("done\n");
}

// Function to perform depth-first search
void depth_first_search(int adjacency_matrix[6][6], int start_node) {
    int visited[6];
    int ds[6]; // stack
    int top = 0;

    ds[top] = start_node;
    top++;
    visited[start_node] = 1;

    while (top > 0) {
        int current_node = ds[top-1];
        printf("%d\n", current_node+1);
        top--;
        for (int i = 0; i < 6; i++) {
            // Check if there is an edge between the current node and the adjacent node
            // and if the adjacent node has not been visited yet
            if (adjacency_matrix[current_node][i] == 1 && visited[i] == 0) {
                ds[top] = i;
                top++;
                visited[i] = 1;
            }
        }
    }
    printf("done\n");
}

int main() {
    int adjacency_matrix[6][6] = {
        //       1  2  3  4  5  6
        {0, 0, 1, 0, 0, 1}, // 1
        {0, 0, 1, 0, 1, 0}, // 2
        {1, 1, 0, 1, 1, 0}, // 3
        {0, 0, 1, 0, 1, 0}, // 4
        {0, 1, 1, 1, 0, 1}, // 5
        {1, 0, 0, 0, 1, 0}  // 6
    };

    // breadth_first_search(adjacency_matrix, 0);
    depth_first_search(adjacency_matrix, 0);
    return 0;
}