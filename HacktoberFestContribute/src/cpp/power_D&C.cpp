#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll x, ll y, ll m)
{
    if (y == 1)
        return x % m;
    if (y == 0)
        return 1;
    if (y & 1)
        return (x * power((x * x) % m, (y - 1) / 2, m)) % m;
    return power((x * x) % m, y / 2, m) % m;
}
