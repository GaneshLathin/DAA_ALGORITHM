
// // You are using GCC
//Insertion sort is a simple sorting algorithm that works by iteratively inserting each 
// element of an unsorted list into its correct position in a sorted portion of the list. It is a 
// stable sorting algorithm, meaning that elements with equal values maintain their relative order in the sorted output.
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0&&a[j-1]>a[j])
        {
            swap(a[j-1],a[j]);
            j--;
        }

    }
    for(auto x: a)
    {
        cout<<x<<" ";
    }
    
}
