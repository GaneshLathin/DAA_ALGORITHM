
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
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(a[j-1]>a[j])
            {
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
           
        }
    }
    for(auto x: a)
    {
        cout<<x<<" ";
    }
    
}