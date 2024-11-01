#include<bits/stdc++.h>
using namespace std;
int Mid(int ss,int se)
{
    return (ss+se)/2;
}
void update(int *st,int ss,int se,int si,int ind,int diff)
{
    if(ind<ss||ind>se)
    {
        return ;
    }
    st[si]+=diff;
    if(ss!=se)
    {
        int mid=Mid(ss,se);
        update(st,ss,mid,si*2+1,ind,diff);
        update(st,mid+1,se,si*2+2,ind,diff);
    }

}
int getSum(int *st,int ss,int se,int qs,int qe,int si)
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
    return getSum(st,ss,mid,qs,qe,si*2+1)+getSum(st,mid+1,se,qs,qe,si*2+2);
}
int constructTree(int a[],int ss,int se,int si,int* st)
{
    if(se==ss)
    {
        st[si]=a[ss];
        return st[si];
    }
    int mid=Mid(ss,se);
    return st[si]=constructTree(a,ss,mid,si*2+1,st)+constructTree(a,mid+1,se,si*2+2,st);
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
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *st = constructSt(a, n);
    constructTree(a, 0, n - 1, 0, st);
    int qs, qe;
    cin >> qs >> qe;
    int ind, el;
    cin >> ind >> el;

    // Save the old value before updating
    int old_val = a[ind];
    a[ind] = el; // Update the array with the new value
    int diff = el - old_val; // Calculate the difference based on the old value

    cout << "Sum of values in given range = " << getSum(st, 0, n - 1, qs, qe, 0);
    update(st, 0, n - 1, 0, ind, diff);
    cout << "Updated sum of values in given range = " << getSum(st, 0, n - 1, qs, qe, 0);

    delete[] st;
}

// 5
// 6 4 3 2 1
// 1 3
// 1 10
// Output 1 :
// Sum of values in given range = 9
// Updated sum of values in given range = 15