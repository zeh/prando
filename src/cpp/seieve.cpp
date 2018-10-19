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

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fst first
#define scd second

#define forn(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define for1(i, n) for (ll(i) = 1; (i) <= (n); ++(i))
#define forr(i, n) for (ll(i) = (n)-1; (i) >= 0; --(i))
#define forab(i, a, b, c) for (ll(i) = a; (i) <= (b); (i) += (c))
#define loop(i, a, n) for (int i = a; i < n; i++)


vll seive;
void Seive()
{
    const ll maxn = 1000005;
    seive.resize(maxn);
    forn(i, maxn) seive[i] = i;
    seive[1] = -1;
    seive[0] = -1;
    forab(i, 2, maxn, 1) if (i == seive[i]) for (ll j = 2 * i; j < maxn; j += i) if (seive[j] == j) seive[j] = i;
}

int main(){
  return 0;
}
