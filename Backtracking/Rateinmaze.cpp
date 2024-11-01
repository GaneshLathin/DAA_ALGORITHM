#include <iostream>
#include <vector>

using namespace std;

// Helper function to find the path and mark it
bool findPathHelper(int row, int col, vector<vector<int>>& a, int n, vector<vector<int>>& vis) {
    // Base case: if reached the bottom-right corner
    if (row == n - 1 && col == n - 1) {
        vis[row][col] = 1; // Mark the destination cell
        return true; // Path found
    }

    // Mark this cell as visited
    vis[row][col] = 1;

    // Check downward
    if (row + 1 < n && a[row + 1][col] == 1 && !vis[row + 1][col]) {
        if (findPathHelper(row + 1, col, a, n, vis)) return true;
    }

    // Check left
    if (col - 1 >= 0 && a[row][col - 1] == 1 && !vis[row][col - 1]) {
        if (findPathHelper(row, col - 1, a, n, vis)) return true;
    }

    // Check right
    if (col + 1 < n && a[row][col + 1] == 1 && !vis[row][col + 1]) {
        if (findPathHelper(row, col + 1, a, n, vis)) return true;
    }

    // Check upward
    if (row - 1 >= 0 && a[row - 1][col] == 1 && !vis[row - 1][col]) {
        if (findPathHelper(row - 1, col, a, n, vis)) return true;
    }

    // Unmark this cell as visited if no path found
    vis[row][col] = 0;
    return false; // No path found
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            cin >> m[row][col];
        }
    }

    vector<vector<int>> vis(n, vector<int>(n, 0));

    if (findPathHelper(0, 0, m, n, vis)) {
        // Print the matrix showing the path
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                cout << vis[row][col] << " ";
            }
            cout << endl;
        }
    } else {
        // If no path, print a message indicating no solution
        cout << "No solution exists";
    }

    return 0;
}
