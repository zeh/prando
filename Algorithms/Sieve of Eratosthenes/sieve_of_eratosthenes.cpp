#include <bits/stdc++.h>
using namespace std;

int prime[100001]={0};

int sieve()
{
    int i,j;
    prime[0]=1;
    prime[1]=1;
    for(i=2;i*i<=100000;i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=100000;j+=i)
                prime[j]=1;
        }
    }
}

int main()
{
    int i,t,l,r;
    cout<<"Enter the no of test ranges:";
    cin>>t;
    sieve();
    while(t--)
    {
        cout<<"Enter the range:";
        cin>>l;
        cin>>r;
        for(i=l;i<=r;i++)
        {
            if(prime[i]==0)
                cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
