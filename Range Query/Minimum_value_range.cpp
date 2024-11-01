// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int Mid(int ss,int se)
{
    return (ss+se)/2;
}
int Min(int ss,int se)
{
    return (ss>se) ? se:ss;
}
int MinValue(int *st,int ss,int se,int qs,int qe,int si)
{
    if(ss>=qs&&se<=qe)
    {
        return st[si];
    }
    if(ss>qe||se<qs)
    {
        return INT_MAX;
    }
    int mid=Mid(ss,se);
    return Min(MinValue(st,ss,mid,qs,qe,si*2+1),MinValue(st,mid+1,se,qs,qe,si*2+2));


}
int ConstructSum(int *st,int ss,int se,int si,int a[])
{
     if(ss==se)
     {
       st[si]=a[ss];
       return st[si];
     }
     int mid=Mid(ss,se);
     st[si]=Min(ConstructSum(st,ss,mid,si*2+1,a),ConstructSum(st,mid+1,se,2*si+2,a));
}
int *ConstructSt(int n,int a[])
{
    int x=(int)(ceil(log2(n)));
    int size=2*(int)pow(2,x)-1;
    int *st=new int[size];
    return st;
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
    int *st=ConstructSt(n,a);
    ConstructSum(st,0,n-1,0,a);
    int qs,qe;
    cin>>qs>>qe;
    cout<<"Minimum of values in range ["<<qs<<", "<<qe<<"] is = "<<MinValue(st,0,n-1,qs,qe,0);

}