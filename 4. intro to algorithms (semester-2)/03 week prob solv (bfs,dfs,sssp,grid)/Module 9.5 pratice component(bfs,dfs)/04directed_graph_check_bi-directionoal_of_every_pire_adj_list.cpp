#include <iostream>
#include <vector>

using namespace std;

// Function to check if a directed graph is bi-directional using adjacency matrix
bool isBidirectionalMatrix(vector<vector<int>> graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && graph[j][i] != 1) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a directed graph is bi-directional using adjacency list
bool isBidirectionalList(vector<vector<int>> graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int node = graph[i][j];
            bool found = false;
            for (int k = 0; k < graph[node].size(); k++) {
                if (graph[node][k] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Input graph as adjacency matrix
    vector<vector<int>> graphMatrix = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 0}
    };

    // Input graph as adjacency list
    vector<vector<int>> graphList = {
        {1},
        {2},
        {0, 3},
        {}
    };

    // Check if graph is bi-directional using adjacency matrix
    if (isBidirectionalMatrix(graphMatrix)) {
        cout << "Graph is bi-directional (using adjacency matrix)." << endl;
    } else {
        cout << "Graph is not bi-directional (using adjacency matrix)." << endl;
    }

    // Check if graph is bi-directional using adjacency list
    if (isBidirectionalList(graphList)) {
        cout << "Graph is bi-directional (using adjacency list)." << endl;
    } else {
        cout << "Graph is not bi-directional (using adjacency list)." << endl;
    }

    return 0;
}

