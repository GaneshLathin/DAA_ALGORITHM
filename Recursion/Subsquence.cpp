#include<bits/stdc++.h>
using namespace std;
void print(int n,int a[],vector<int> &v,int id)
{
    if(id==n)
    {
        for(auto x: v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    v.push_back(a[id]);
    print(n,a,v,id+1);
    v.pop_back();
    print(n,a,v,id+1);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>v;
    print(n,a,v,0);
}