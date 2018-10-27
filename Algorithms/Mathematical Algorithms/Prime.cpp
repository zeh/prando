/*
* Program to compute list of prime numbers
* upto a given limit using Sieve of Eratosthenes
* Language: C++
*/
#include<iostream>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;

vector<ll int> primes;
void sieve(ll int n)
{
    bool a[n+1];
    memset(a,1,sizeof(a));
    ll int count = 0;
    for(ll int i=2; i*i<=n; i++)
    {
        if(a[i])
        {
            for(ll int j=i*i; j<=n; j+=i)
                a[j] = 0;
        }
    }
    for(ll int i=2; i<=n; i++)
        if(a[i]) primes.push_back(i);
}

int main()
{
    ll int n;
    cin>>n;
    sieve(n);
    for(ll int i=0; i<primes.size(); i++)
        cout<<primes[i]<<" ";
    cout<<endl;
}
