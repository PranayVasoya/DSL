#include <stdio.h>
#include <limits.h>

#define MAX 20

struct Graph {
    int v;
    int costMatrix[MAX][MAX];
};

// Declare the dfs function before it's used.
void dfs(struct Graph* graph, int vertex, int visited[]);

void create(struct Graph* graph, int start, int end, int weight) {
    graph->costMatrix[start][end] = weight;
    graph->costMatrix[end][start] = weight;
}

void display(struct Graph* graph) {
    for (int i = 0; i < graph->v; ++i) {
        for (int j = 0; j < graph->v; ++j) {
            printf("%d ", graph->costMatrix[i][j]);
        }
        printf("\n");
    }
}

void primsMST(struct Graph* graph) {
    // (unchanged)
}

void dfsTraversal(struct Graph* graph, int start) {
    int visited[MAX];
    for (int i = 0; i < graph->v; i++) {
        visited[i] = 0;
    }
    dfs(graph, start, visited);
}

void dfs(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < graph->v; i++) {
        if (graph->costMatrix[vertex][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph g;
    g.v = vertices;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            g.costMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int start, end, weight;
        printf("Enter edge %d start, end and weight: ", i + 1);
        scanf("%d %d %d", &start, &end, &weight);
        create(&g, start, end, weight);
    }

    printf("Adjacency matrix of the graph:\n");
    display(&g);

    printf("Depth-first traversal of the graph starting from vertex 0:\n");
    dfsTraversal(&g, 0);

    return 0;
}
