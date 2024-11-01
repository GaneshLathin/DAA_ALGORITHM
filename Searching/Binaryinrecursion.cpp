// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int serach(int low,int high,int a[],int d)
{
    if(high>=low)
    {
        int mid=(low+high)/2;
        if(a[mid]==d)
        {
            return true;
        }
        if(a[mid]>d)
        {
            return serach(low,mid-1,a,d);
        }
        return serach(mid+1,high,a,d);
    }
    return false;
}
int main()
{
    int n,d;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cin>>d;
    if(serach(0,n-1,a,d))
    {
        cout<<"Key found";
    }
    else
    {
        cout<<"Key not found";
    }
   
}