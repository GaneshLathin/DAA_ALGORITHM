#include <bits/stdc++.h>

using namespace std;


bool solve(int n, int i, int j, int cnt, vector<vector<int>>& mat, vector<vector<bool>>& visited) {

    if (cnt == (n * n - 1)) {
        mat[i][j]=cnt;
        return true;
    }

    mat[i][j] = cnt;
    visited[i][j] = true;

    if(i>=0 &&j<n&& !visited[i-2][j+1])
    {
    if(solve(n, i - 2, j + 1, cnt + 1, mat, visited))
    {
        return true;
    }
    }
    if(i>=0 &&j>=0&& !visited[i-2][j-1])
    {
    if(solve(n, i - 2, j - 1, cnt + 1, mat, visited))
    {
        return true;
    }
    }
    if(i<n &&j<n&& !visited[i+2][j+1])
    {
    if(solve(n, i + 2, j + 1, cnt + 1, mat, visited))
    {
        return true;
    }
    }
    if(i<n &&j>=0&& !visited[i+2][j-1])
    {
    if(solve(n, i + 2, j - 1, cnt + 1, mat, visited))
    {
        return true;
    }
    }
    if(i>=0 &&j<n&& !visited[i-1][j+2])
    {
    if(solve(n, i - 1, j + 2, cnt + 1, mat, visited))
    {
        return true;
    }
    }
    if(i>=0 &&j>=0&& !visited[i-1][j-2])
    {
    if(solve(n, i - 1, j - 2, cnt + 1, mat, visited))
    {
        return true;
    }
    }
    if(i<n &&j<n&& !visited[i+1][j+2])
    {
    if(solve(n, i + 1, j + 2, cnt + 1, mat, visited))
    {
        return true;
    }
    }
    if(i<n &&j>=0&& !visited[i+1][j-2])
    {
    if(solve(n, i + 1, j - 2, cnt + 1, mat, visited))
    {
        return true;
    }
    }

    // Backtrack
    visited[i][j] = false;
    mat[i][j] = 0;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    

    if (solve(n,0,0,0,mat,visited)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
