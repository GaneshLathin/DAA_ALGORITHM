#include<bits/stdc++.h>
using namespace std;
void print(int n,int k,int i,vector<int>&v,int a[])
{
    if(n==i)
    {
        if(k==0)
        {
            for(auto x: v)
            {
                cout<<x<<" ";
            }
            cout<<endl;
            return ;
        }
    }
    else{
        if(a[i]<=k)
        {
            v.push_back(a[i]);
            print(n,k-a[i],i,v,a);
            v.pop_back();

        }
        print(n,k,i+1,v,a);
    }
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
    int k;
    cin>>k;
    vector<int>v;
    print(n,k,0,v,a);
}