#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

// Function to perform parallel DFS
void parallelDFS(vector<vector<int>>& graph, int currentNode, vector<bool>& visited) {
    // Mark the current node as visited
    visited[currentNode] = true;

    // Traverse neighbors of the current node in parallel
    #pragma omp parallel for
    for (int i = 0; i < graph[currentNode].size(); ++i) {
        int neighbor = graph[currentNode][i];
        if (!visited[neighbor]) {
            // Recursively explore the neighbor
            parallelDFS(graph, neighbor, visited);
        }
    }
}

int main() {
    int numNodes = 6;
    vector<vector<int>> graph(numNodes);

    // Define the graph (example)
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {2};
    graph[5] = {3};

    // Vector to keep track of visited nodes
    vector<bool> visited(numNodes, false);

    // Starting node for DFS
    int startNode = 0;

    // Perform parallel DFS
    parallelDFS(graph, startNode, visited);

    // Output the visited array
    cout << "Visited array after DFS:\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << visited[i] << " ";
    }
    cout << endl;

    return 0;
}
