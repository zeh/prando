#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,three,five,fifteen;
    cin>>n;
    n=n-1;
    three=n/3;
    five=n/5;
    fifteen=n/15;
    long long int ans;
    ans=(3*(three*(three+1)/2))+(5*(five*(five+1)/2))-(15*(fifteen*(fifteen+1)/2));
    cout<<ans<<endl;
    return 0;
}
