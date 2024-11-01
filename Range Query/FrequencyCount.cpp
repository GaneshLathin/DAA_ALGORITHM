// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int Mid(int ss,int se)
{
    return (ss+se)/2;
}
int Freq(int *st,int ss,int se,int si,int qs,int qe)
{
    if(ss>=qs&&se<=qe)
    {
        return st[si];
    }
    if(ss>qe||se<qs)
    {
        return 0;
    }
    int mid=Mid(ss,se);
    return Freq(st,ss,mid,si*2+1,qs,qe)+Freq(st,mid+1,se,si*2+2,qs,qe);
}
int constructTree(int a[],int ss,int se,int si,int* st,int num)
{
    if(se==ss)
    {
        if(num==a[ss])
        {
        st[si]=1;

        }
        else{
            st[si]=0;
        }
        return st[si];
    }
    int mid=Mid(ss,se);
  return st[si]=constructTree(a,ss,mid,si*2+1,st,num)+constructTree(a,mid+1,se,si*2+2,st,num);
}
int *constructSt(int a[],int n)
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
    int qs,qe;
    cin>>qs>>qe;
    int num;
    cin>>num;
    int *st = constructSt(a, n);
    constructTree(a, 0, n - 1, 0, st,num);
    cout<<"Frequency of "<<num<<" in the range ["<<qs<<", "<<qe<<"] is: "<<Freq(st,0,n-1,0,qs-1,qe-1);
  

}