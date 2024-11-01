// Binary Search Algorithm is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half.
//  The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N). 
// Time Complexity: O(log N)
// Auxiliary Space: O(1)


#include<iostream>
using namespace std;
int main()
{
    int n,d;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>d;
    int left=0,right=n-1,mid=0;
    while(right>=left)
    {
    mid=(left+right)/2;
    if(a[mid]==d)
    {
        cout<<mid;
        return 0;
    }
    else
    {
        if(a[mid]>d)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
        
    }
    cout<<"NO OCCURRENCES";
}