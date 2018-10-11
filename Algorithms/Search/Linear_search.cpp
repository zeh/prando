#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	unsigned long long int n,i,*arr;
	long long int x;
	int flag=1;
	cout<<"Enter the size of the array which you want to search: ";
	cin>>n;
	arr= new long long int [n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//not sorting as it will take nlog(n) instead of n incase of searching without sorting
	cout<<endl<<"Enter the number to search: ";
	cin>>x;
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			cout<<"The point is present in position "<<i;
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"The point is not present"<<endl;
	}
	delete [] arr;
	return 0;
}