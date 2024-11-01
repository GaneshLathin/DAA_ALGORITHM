// // The linear search algorithm is defined as a sequential search algorithm that starts at one end 
// // and goes through each element of a list until the desired element is found; otherwise, 
// // the search continues till the end of the dataset.
// Average Case: O(N)
// Auxiliary Space: O(1) as except for the variable to iterate through the list, no other variable is used. 

// You are using GCC
#include<iostream>
using namespace std;
int main()
{
    int n,d;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>d;
    for(auto x: a)
    {
        if(x==d)
        {
            cout<<d<<" is present";
            return 0;
        }
    }
    cout<<d<<" is not present";
}