#include<bits/stdc++.h>
using namespace std;
void print(int n,int id,int a[])
{
    if(n==id)
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
        return ;

    }
    else{
        for(int i=id;i<n;i++)
        {
            swap(a[i],a[id]);
            print(n,id+1,a);
            swap(a[i],a[id]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    print(n,0,a);
}
//APproach 2
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void perm(int n,string s,int id)
{
    if(n==id)
    {
      cout<<s<<endl;
      return ;
    }
    for(int i=id;i<n;i++)
    {
        swap(s[i],s[id]);
        perm(n,s,id+1);
        swap(s[i],s[id]);
    }
}
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    perm(n,s,0);
}