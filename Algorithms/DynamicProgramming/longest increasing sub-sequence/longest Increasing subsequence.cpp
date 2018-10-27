//printing the longest increasing sub-sequence in the given array

#include <bits/stdc++.h>
using namespace std;

void lis(int a[],int n)
{
    int i,j,index;
    int lis[n];
    for(i=0;i<n;i++)
        lis[i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if((a[i]>a[j])&&(lis[i]<lis[j]+1))
                lis[i]=lis[j]+1;
        }
    }
    int max=a[0];
    for(i=1;i<n;i++)
    {
        if(max<lis[i])
        {
            max=lis[i];
            index=i;
        }
    }
    j=1;
    for(i=0;i<n && j<=max;i++)
    {
        if(lis[i]==j)
        {
            cout<<a[i]<<endl;
            j++;
        }
    }
}

int main()
{
    int n,i;
    cout<<"Enter the number of elements in the sequence:";
    cin>>n;
    int seq[n];
    for(i=0;i<n;i++)
        cin>>seq[i];
    cout<<"The longest increasing subsequence is:\n";
    lis(seq,n);
    return 0;
}
