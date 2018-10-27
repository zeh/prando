//   @author - rushitjasani

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define mp make_pair
#define pb push_back
#define MOD 1000000007


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

ll modinv(ll x, ll mod = MOD)
{
    return power(x, mod - 2, mod);
}
