// Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.

// Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.



// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v=5;
    vector<vector<int>>adj[v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            int el;
            cin>>el;
            if(el!=0)
            {
                adj[i].push_back({j,el});
            }
        }
    }
    int s;
    cin>>s;
    vector<int>dis(v,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    dis[s]=0;
    while(!pq.empty())
    {
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(auto x: adj[node])
        {
            int ve=x[0];
            int w=x[1];
            if(d+w<dis[ve])
            {
                dis[ve]=d+w;
                pq.push({d+w,ve});
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    for(int i=0;i<v;i++)
    {
    printf("%d\t\t%d\n",i,dis[i]);
    }
    
}