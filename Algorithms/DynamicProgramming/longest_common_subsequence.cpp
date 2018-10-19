#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007 
#define ll long long
#define pb push_back
#define nl printf("\n");

int dp[200][200];

int lcs(string a,string b,int n,int m)
{
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(n==0 || m==0)
		return dp[n][m] = 0;
	if(a[n-1] == b[m-1])
		return dp[n][m] = 1 + lcs(a,b,n-1,m-1);
	else
		return dp[n][m] = max(lcs(a,b,n-1,m), lcs(a,b,n,m-1));
}

int main()
{
    ifstream myFile("task.in");
    if(!myFile.fail())
    {
        assert(freopen("task.in", "r", stdin));
    }
	for(int i=0;i<200;i++)
		for(int j=0;j<200;j++) dp[i][j]=-1;

	int n,m;
	cin>>n>>m;
	string a,b;
	cin>>a>>b;
	cout<<lcs(a,b,n,m);nl

    return 0;
}
