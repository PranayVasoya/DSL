#include <stdio.h>
#include<stdlib.h>
struct Graph {
    int numVertices;
    int **adjacencyMatrix; 
};
void initializeGraph(struct Graph *graph, int numVertices) {
    graph->numVertices = numVertices;
    graph->adjacencyMatrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int *)malloc(numVertices * sizeof(int));
    }
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}
void addEdge(struct Graph *graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjacencyMatrix[src][dest] = 1;
        graph->adjacencyMatrix[dest][src] = 1; 
    }
}
void insertNode(struct Graph *graph, int newNode) {
    if (newNode >= 0 && newNode < graph->numVertices) {
        graph->numVertices++;
        graph->adjacencyMatrix = (int **)realloc(graph->adjacencyMatrix, graph->numVertices * sizeof(int *));
        for (int i = 0; i < graph->numVertices; i++) {
            graph->adjacencyMatrix[i] = (int *)realloc(graph->adjacencyMatrix[i], graph->numVertices * sizeof(int));
        }
        for (int i = 0; i < graph->numVertices; i++) {
            graph->adjacencyMatrix[i][newNode] = 0;
            graph->adjacencyMatrix[newNode][i] = 0;
        }
    }
}
void deleteNode(struct Graph *graph, int nodeToDelete) {
    if (nodeToDelete >= 0 && nodeToDelete < graph->numVertices) {
        for (int i = 0; i < graph->numVertices; i++) {
            graph->adjacencyMatrix[i][nodeToDelete] = 0;
            graph->adjacencyMatrix[nodeToDelete][i] = 0;
        }
        graph->numVertices--;
        graph->adjacencyMatrix = (int **)realloc(graph->adjacencyMatrix, graph->numVertices * sizeof(int *));
        for (int i = 0; i < graph->numVertices; i++) {
            graph->adjacencyMatrix[i] = (int *)realloc(graph->adjacencyMatrix[i], graph->numVertices * sizeof(int));
        }
    }
}
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    struct Graph g;
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    initializeGraph(&g, numVertices);
    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }
    int choice;
    do {
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Print Graph\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int newNode;
                printf("Enter the node to insert: ");
                scanf("%d", &newNode);
                insertNode(&g, newNode);
                break;
            }
            case 2: {
                int nodeToDelete;
                printf("Enter the node to delete: ");
                scanf("%d", &nodeToDelete);
                deleteNode(&g, nodeToDelete);
                break;
            }
            case 3:
                printGraph(&g);
                break;
        }
    } while (choice != 4);
    for (int i = 0; i < g.numVertices; i++) {
        free(g.adjacencyMatrix[i]);
    }
    free(g.adjacencyMatrix);

    return 0;
}
