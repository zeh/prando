
// BY hg398 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

int main() {
	boost;
	int num;
	cin>>num;													//input number
	bitset <64> bit_rep=num;									//bitset to convert number into binary representation
	for(int i=63;i>=0;i--)cout<<bit_rep[i];						//printing binary representation
	return 0;
}