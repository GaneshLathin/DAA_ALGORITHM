// Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.

// Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,E;
    cin>>v>>E;
    vector<vector<int>>mat(v,vector<int>(v,INT_MAX));
    for(int i=0;i<E;i++)
    {
        int s,e,w;
        cin>>s>>e>>w;
        mat[s][e]=w;
        mat[e][s]=w;
    }
    for(int i=0;i<v;i++)
    {
        mat[i][i]=0;
    }
    cout<<"Original matrix"<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(mat[i][j]==INT_MAX)
            {
                cout<<"INF ";
            }
            else
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Shortest path matrix"<<endl;
    for(int via=0;via<v;via++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(mat[i][via]!=INT_MAX&&mat[via][j]!=INT_MAX)
                {
                mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
           
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
//to print Adjency List

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int V = 5;
//     int matrix[V][V];

//     // Input adjacency matrix
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             cin >> matrix[i][j];
//         }
//     }

//     // Create adjacency list
//     vector<vector<int>> adj[V];
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             if (matrix[i][j] != 0) {
//                 adj[i].push_back({j, matrix[i][j]});
//             }
//         }
//     }

//     // Print adjacency list
//     cout << "Adjacency List:\n";
//     for (int i = 0; i < V; i++) {
//         cout << i << ": ";
//         for (const auto& edge : adj[i]) {
//             cout << "(" << edge[0] << ", " << edge[1] << ") ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
