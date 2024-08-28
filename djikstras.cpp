#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }

    return minIndex;
}
void printSolution(const vector<int>& dist) {
    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < dist.size(); i++)
        cout << i << " \t\t" << dist[i] << endl;
}
void dijkstra(const vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX); 
    vector<bool> sptSet(V, false); 
    dist[src] = 0; 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int V; 
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, src, V);

    return 0;
}
