#include <bits/stdc++.h>

using namespace std;

const int N = 10000000;
int lp[N+1];
vector<int> prime;

void sieve(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            prime.push_back (i);
        }
        for (int j=0; j<(int)prime.size() && prime[j]<=lp[i] && i*prime[j]<=N; ++j)
            lp[i * prime[j]] = prime[j];
    }
}

int main(){

    sieve();
    int n;
    cin>>n;
    
    for(int i=0;i<=n;i++){
        cout<<prime[i]<<" ";
    }
    cout<<'\n';
}
