#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int src, dest, weight;
};

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}


void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}


void kruskalMST(vector<Edge>& edges, int V) {
   
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<Edge> result; 
    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (const auto& edge : edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);

        if (x != y) {
            result.push_back(edge);
            unionSets(parent, rank, x, y);
        }
    }

    cout << "Edges in the MST:\n";
    for (const auto& edge : result)
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
}

int main() {
    int V, E; 
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter the edges in the format (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(edges, V);

    return 0;
}
