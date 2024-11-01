#include<bits/stdc++.h>
using namespace std;
void print(int n,int a[],vector<int> &v,int id,int sum,int k)
{
    if(id==n)
    {
        if(k==sum)
        {
        for(auto x: v)
        {
            cout<<x<<" ";
        }
            
        }
        cout<<endl;
        return;
    }
    v.push_back(a[id]);
    sum+=a[id];
    
    print(n,a,v,id+1,sum,k);
    v.pop_back();
    sum-=a[id];
    print(n,a,v,id+1,sum,k);
}
int main()
{
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    vector<int>v;
    int sum=0;
    print(n,a,v,0,sum,k);
}