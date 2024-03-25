#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AIRPORTS 100
#define MAX_NEIGHBOURS 10

// Define a structure to represent an airport node
typedef struct Node {
    char name[10];
    int neighbourCount;
    struct Node* neighbours[MAX_NEIGHBOURS];
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->neighbourCount = 0;
    return newNode;
}

void addNeighbour(Node* node, Node* neighbour) {
    if (node->neighbourCount < MAX_NEIGHBOURS) {
        node->neighbours[node->neighbourCount++] = neighbour;
    }
}

Node* findNodeByName(Node** nodes, int count, char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(nodes[i]->name, name) == 0) {
            return nodes[i];
        }
    }
    return NULL;
}

int areNodesLinked(Node* node1, Node* node2) {
    for (int i = 0; i < node1->neighbourCount; i++) {
        if (node1->neighbours[i] == node2) {
            return 1;
        }
    }
    return 0;
}

void makeAirportGraph(Node** airports, int* count) {
    // Create airport nodes
    Node* yyz = createNode("YYZ");
    Node* yvr = createNode("YVR");
    Node* yul = createNode("YUL");
    Node* whitehorse = createNode("Whitehorse");

    // Add neighbours to each airport node
    addNeighbour(yyz, yvr);
    addNeighbour(yyz, yul);
    addNeighbour(yvr, yyz);
    addNeighbour(yvr, yul);
    addNeighbour(yvr, whitehorse);
    addNeighbour(yul, yyz);
    addNeighbour(yul, yvr);
    addNeighbour(whitehorse, yvr);

    // Add airport nodes to the airports array
    airports[(*count)++] = yyz;
    airports[(*count)++] = yvr;
    airports[(*count)++] = yul;
    airports[(*count)++] = whitehorse;
}

int main() {
    Node* airports[MAX_AIRPORTS];
    int count = 0;

    // Create the airport graph
    makeAirportGraph(airports, &count);

    // Find nodes by name
    Node* yyz = findNodeByName(airports, count, "YYZ");
    Node* yul = findNodeByName(airports, count, "YUL");

    // Check if nodes are linked and print the result
    if (yyz && yul && areNodesLinked(yyz, yul)) {
        printf("Toronto (YYZ) is connected to Montreal (YUL)? Yes\n");
    } else {
        printf("Toronto (YYZ) is connected to Montreal (YUL)? No\n");
    }

    // Free allocated memory (not shown for brevity)
    return 0;
}
