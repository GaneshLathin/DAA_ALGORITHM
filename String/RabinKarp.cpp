// You are using GCC
// Time Complexity: 

// The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
// The worst case of the Rabin-Karp algorithm occurs when all characters of pattern and text are the same as the hash values of all the substrings of T[] match with the hash value of P[]. 
// Auxiliary Space: O(1)
// Given a text T[0. . .n-1] and a pattern P[0. . .m-1], write a function search(char P[], char T[]) 
// that prints all occurrences of P[] present in T[] using Rabin Karp algorithm. You may assume that n > m.
#include<bits/stdc++.h>
using namespace std;
void RK(string t,string p)
{
    int l1=t.length();
    int l2=p.length();
    int k=l2-1,p1=0,t1=0,d=10,j,c=0;
    int f=pow(d,k);
    for(int i=0;i<l2;i++)
    {
        p1+=pow(d,k)*p[i];
        t1+=pow(d,k)*t[i];
        k--;
    }
    for(int i=0;i<=l1-l2;i++)
    {
        if(p1==t1)
        {
            for(j=0;j<l2;j++)
            {
                if(t[i+j]!=p[j])
                {
                    break;
                }
            }
            if(j==l2)
            {
                cout<<"Pattern found at index "<<i<<endl;
                c=1;
            }
        }
        t1=(t1-(t[i]*f))*d+t[i+l2];
    }
        if(c==0)
        {
            cout<<"Not Found";
        }
}
int main()
{
    string t,p;
    cin>>t>>p;
    RK(t,p);
}