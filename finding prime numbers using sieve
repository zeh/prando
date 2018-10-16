#include<bits/stdc++.h>
using namespace std;
void iprime(int n,vector<int> &prime)
{
    vector<int> mark(n+2,1);
    for(int i=3;i<=n;i+=2)
    {
        if(mark[i])
        {
            for(int j=i*3;j<=n;j+=2*i)
            {
                mark[j]=0;
            }
        }
    }
    prime.push_back(2);
    cout<<"2 ";
    for(int i=3;i<=n;i+=2)
    {
        if(mark[i]) prime.push_back(i);
        cout<<i<<" ";
    }
    
}
int main()
{
    int n;  cin>>n;
    vector<int>  prime;
    iprime(n,prime);
    return 0;
}
