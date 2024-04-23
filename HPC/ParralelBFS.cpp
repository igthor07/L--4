/* 6. Implement Parallel breadth first search using OpenMP */

#include <iostream>
#include <queue>
#include <vector>
#include <omp.h>

using namespace std;

// Function to perform parallel BFS
void parallelBFS(vector<vector<int>>& graph, int startNode, vector<bool>& visited) {
    int numNodes = graph.size();
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        #pragma omp parallel
        {
            #pragma omp for
            for (int i = 0; i < q.size(); ++i) {
                int currentNode;
                #pragma omp critical
                {
                    currentNode = q.front();
                    q.pop();
                }

                // Traverse neighbors of the current node
                for (int j = 0; j < numNodes; ++j) {
                    if (graph[currentNode][j] && !visited[j]) {
                        #pragma omp critical
                        {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int numNodes = 6;
    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));
    vector<bool> visited(numNodes, false);

    // Define the graph (example)
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][5] = graph[5][3] = 1;

    // Starting node for BFS
    int startNode = 0;

    // Perform parallel BFS
    parallelBFS(graph, startNode, visited);

    // Output the visited array
    cout << "Visited array after BFS:\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << visited[i] << " ";
    }
    cout << endl;

    return 0;
}
