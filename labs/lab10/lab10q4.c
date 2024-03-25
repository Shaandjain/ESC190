#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AIRPORTS 50

// Graph structure using an adjacency matrix
typedef struct Graph {
    int matrix[MAX_AIRPORTS][MAX_AIRPORTS];
    char* airports[MAX_AIRPORTS]; 
    int airportCount;
} Graph;

// Function to create a new graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph)); // Allocate memory for the graph structure
    graph->airportCount = 0; // Initialize airport count to 0
    for (int i = 0; i < MAX_AIRPORTS; i++) {
        for (int j = 0; j < MAX_AIRPORTS; j++) {
            graph->matrix[i][j] = 0; // Initialize matrix with 0s to represent no connections
        }
        graph->airports[i] = NULL; // Initialize airport names to NULL
    }
    return graph;
}

// Function to add a new airport to the graph
int addAirport(Graph* graph, char* name) {
    if (graph->airportCount < MAX_AIRPORTS) {
        graph->airports[graph->airportCount] = strdup(name); // Duplicate and store the airport name
        return graph->airportCount++; 
    }
    return -1; // Error or graph full
}

// Function to get the index of a given airport name in the graph
int get_ind_from_str(char *str, char **strs, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(str, strs[i]) == 0) {
            return i; // Return the index if the airport name is found
        }
    }
    return -1; // Not found
}

// Function to add an edge between two airports in the graph
void addEdge(Graph* graph, char* src, char* dest) {
    int srcIndex = get_ind_from_str(src, graph->airports, graph->airportCount); 
    int destIndex = get_ind_from_str(dest, graph->airports, graph->airportCount); 

    if (srcIndex != -1 && destIndex != -1) {
        graph->matrix[srcIndex][destIndex] = 1; 
        graph->matrix[destIndex][srcIndex] = 1; 
    }
}

// Function to check if two airports are connected in the graph
int areConnected(Graph* graph, char* src, char* dest) {
    int srcIndex = get_ind_from_str(src, graph->airports, graph->airportCount); 
    int destIndex = get_ind_from_str(dest, graph->airports, graph->airportCount); 

    if (srcIndex != -1 && destIndex != -1) {
        return graph->matrix[srcIndex][destIndex]; 
    }
    return 0; // Not connected
}

// Function to free the memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->airportCount; i++) {
        free(graph->airports[i]); 
    }
    free(graph); 
}

int main() {
    Graph* graph = createGraph(); 

    addAirport(graph, "YYZ"); 
    addAirport(graph, "YVR"); 
    addAirport(graph, "YUL"); 

    addEdge(graph, "YYZ", "YVR"); 
    addEdge(graph, "YYZ", "YUL"); 

    printf("YYZ and YUL are connected? %d\n", areConnected(graph, "YYZ", "YUL")); // Check if "YYZ" and "YUL" are connected

    freeGraph(graph); // Free the memory allocated for the graph

    return 0;
}