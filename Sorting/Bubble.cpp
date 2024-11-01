// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the
//  adjacent elements if they are in the wrong order. This algorithm is not suitable for
// //   large data sets as its average and worst-case time complexity is quite high.
// Time Complexity: O(N2)
// Auxiliary Space: O(1)
// You are using GCC
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int d=a[j];
                a[j]=a[j+1];
                a[j+1]=d;
            }
        }
    }
    for(auto x :a)
    {
        cout<<x<<" ";
    }
}