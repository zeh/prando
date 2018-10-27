
// BY hg398 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

int largest(int a,int b)
{
	return a*(bool)(a/b) + b*(bool)(b/a); 
}

int main() {
	boost;
	int num1,num2;
	cin>>num1>>num2;
	if(num1==num2)
	cout<<num1;
	else
	cout<<largest(num1,num2);
	return 0;
}