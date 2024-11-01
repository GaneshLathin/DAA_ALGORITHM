#include <bits/stdc++.h>
using namespace std;

// Function to check if it is safe to place a queen at (row, col)
bool isSafe(int row, int col, vector<vector<int>> &v, int n)
{
    // Check row on the left side
    for (int i = 0; i < col; i++)
    {
        if (v[row][i])
            return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (v[i][j])
            return false;
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (v[i][j])
            return false;
    }

    return true;
}

// Recursive function to place queens on the board
bool Place(vector<vector<int>> &v, int col, int n)
{
    // If all queens are placed
    if (col >= n)
    {
        return true;
    }

    // Try placing a queen in each row of the current column
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, v, n))
        {
            v[i][col] = 1; // Place the queen
            if (Place(v, col + 1, n)) // Recursively place the next queen
            {
                return true;
            }
            v[i][col] = 0; // Backtrack if placing queen here doesn't lead to a solution
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0)); // Initialize the board with 0s

    // Try to place queens starting from the first column
    if (Place(v, 0, n))
    {
        // Print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution";
    }

    return 0;
}
