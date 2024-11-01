// // Merge sort is a sorting algorithm that follows the divide-and-conquer approach. 
// // It works by recursively dividing the input array into smaller subarrays and sorting 
// // those subarrays then merging them back together to obtain the sorted array.
// Time Complexity:
// Best Case: O(n log n), When the array is already sorted or nearly sorted.
// Average Case: O(n log n), When the array is randomly ordered.
// Worst Case: O(n log n), When the array is sorted in reverse order.
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void mergesort(int a[],int low,int high,int mid)
{
    int left=low;
    int right=mid+1;
    vector<int>v1;
    while(left<=mid&&right<=high)
    {
        if(a[left]<a[right])
        {
            v1.push_back(a[left]);
            left++;
        }
        else
        {
            v1.push_back(a[right]);
            right++;
            
        }
    }
    while(left<=mid)
    {
        v1.push_back(a[left]);
        left++;
    }
    while(right<=high)
    {
        v1.push_back(a[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=v1[i-low];
    }
}
void merge(int a[],int low,int high)
{
    if(low>=high)
    {
        return;
    }
    else
    {
        int mid=(low+high)/2;
        merge(a,low,mid);
        merge(a,mid+1,high);   
        mergesort(a,low,high,mid);
    }
}
int main()
{
    int n;
    cin>>n;
    int s=n*n;
    int a[s];
    for(int i=0;i<s;i++)
    {
        cin>>a[i];
    }
    merge(a,0,s-1);
    for(int i=0;i<s;i++)
    {
       if((i+1)%n==0)
       {
           cout<<a[i]<<endl;
       }
       else
       {
           cout<<a[i]<<" ";
       }
    }
}