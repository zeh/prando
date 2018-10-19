#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	int l=arr[0],sl=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]>l)
		{
		sl=l;
		l=arr[i];
		}
		else if(arr[i]>sl && arr[i]!=l)
		sl=arr[i];
	}
	cout<<"Secong largest integer is: "<<sl;
}
