// You are using GCC
// Time Complexity: O( N^M) (n raised to m)

// Space Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;

// Function to check if it's safe to color the node with the given color
bool isSafe(int node, int color[], vector<int> graph[], int col) {
    for (int neighbor : graph[node]) {
        if (color[neighbor] == col) {
            return false; // Color conflict
        }
        
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool solve(int node, int color[], int m, int N, vector<int> graph[]) {
    if (node == N) {
        return true; // All nodes are colored
    }

    for (int i = 1; i <= m; i++) { // Try all colors
        if (isSafe(node, color, graph, i)) {
            color[node] = i; // Assign color
            if (solve(node + 1, color, m, N, graph)) return true; // Recur
            color[node] = 0; // Backtrack
        }
    }
    return false; // No color can be assigned
}

int main() {
    int n, e, m;
    cin >> n >> e >> m;
    
    int col[n] = {0}; // Array to store colors of nodes
    vector<int> graph[n]; // Adjacency list representation of the graph

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1); // Adjusting for 0-based index
        graph[v - 1].push_back(u - 1);
    }

    if (solve(0, col, m, n, graph)) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            cout << col[i] << " "; // Output colors
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
