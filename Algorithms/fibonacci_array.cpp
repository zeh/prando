#include <iostream>
using namespace std;

int main() {
int i,k[47],n;
cin>>n;
k[0]=0;
k[1]=1;
for(i=2;i<n;i++)
	k[i] = k[i-1] + k[i-2];
for(i=0;i<n-1;i++)
	cout<<k[i]<<" ";
cout<<k[i]<<endl;
return 0;
}

// takes an input n and prints first n terms of the fibonacci series
