#include<bits/stdc++.h>
using namespace std;
void print(int n,int k,int i,vector<int>&v,int a[],int &c)
{
    if(n==i)
    {
        if(k==0)
        {
            c++;
            return ;
        }
    }
    else{
        if(a[i]<=k)
        {
            v.push_back(a[i]);
            print(n,k-a[i],i,v,a,c);
            v.pop_back();

        }
        print(n,k,i+1,v,a,c);
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
    int c=0;
    print(n,k,0,v,a,c);
    cout<<c;
}