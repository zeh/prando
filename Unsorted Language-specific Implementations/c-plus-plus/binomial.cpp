#include<bits\stdc++.h>
using namespace std;
int fact(int);
int main()
{
	int n,k;
	float res;
	cout<<"Enter 2 integers";
	cin>>n>>k;
	res=fact(n)/(fact(n-k)*fact(k));
	cout<<"Result="<<res;
}
int fact(int n)
{
	if(n==0)
	return 1;
	else
	return n*fact(n-1);
}
