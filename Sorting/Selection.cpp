// // Selection sort is a simple and efficient sorting algorithm that works by repeatedly selecting the smallest
// //  (or largest) element from the unsorted portion of the list and moving it to the sorted portion of the list.
// Time Complexity: The time complexity of Selection Sort is O(N2) as there are two nested loops:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
              if(a[j]<a[min])
              {
                min=j;
              }
        }
       swap(a[i],a[min]);
    }
}