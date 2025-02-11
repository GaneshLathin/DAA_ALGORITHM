// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,maxi=0;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int ek;
        cin>>ek;
        v.push_back(ek);
    }
    vector<int>v1(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                v1[i]=max(v1[i],1+v1[j]);
            }
        }
        maxi=max(maxi,v1[i]);
    }
    cout<<"Length of the longest increasing subsequence: "<<maxi;
    
}
