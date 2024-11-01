// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    int a;
    cin>>a;
    int dp[n+1][a+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=a;j++)
        {
            if(j==0 || i==0 )
            {
                dp[i][j]=0;
            
            }
            else if(c[i-1]<=j)
            {
                int rem=j-c[i-1];
                dp[i][j]=1+dp[i][rem];
            }
            else if(c[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
        }

    }
             cout<<dp[n][a]<<" ";
}