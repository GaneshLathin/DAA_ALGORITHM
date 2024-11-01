// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int print(int n,int k,int i,int sum,int a[])
{
    if(n==i)
    {
        if(sum==k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        sum+=a[i];
        int l=print(n,k,i+1,sum,a);
        sum-=a[i];
        int r=print(n,k,i+1,sum,a);
        return r+l;
    
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
    cout<<print(n,k,0,0,a);
} 