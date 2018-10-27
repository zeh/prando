#include<bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int x)
    {
        return (x && !(x & (x - 1)));
    }
int main()
{
	int n;
	cout<<"enter the number to test ";
	cin>>n;
	int ans = isPowerOfTwo(n);
	if(ans == 1)
		cout<<"yes";
	else
		cout<<"no";
}    