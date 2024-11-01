// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).

// Space Complexity: O(N)
#include <bits/stdc++.h>

using namespace std;

// Recursive function to solve the N-Queens problem
bool solve(int col, vector<vector<int>> &board, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
    if (col == n) {
        return true;  // A solution has been found
    }
    for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 1;  // Place a queen
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            if (solve(col + 1, board, leftrow, upperDiagonal, lowerDiagonal, n)) {
                return true;
            }
            // Backtrack
            board[row][col] = 0;
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
    return false;  // No solution found
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize board with 0
    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

    if (solve(0, board, leftrow, upperDiagonal, lowerDiagonal, n)) {
        // Print the found solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";  // Output integers with a space
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}
