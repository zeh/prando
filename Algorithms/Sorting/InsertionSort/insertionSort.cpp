#include<iostream>
using namespace std;

int main{
	int n=20, i;
	int arr[n];
	for(i=0; i<n; i++){
		cin>>arr[i];
	}
	for(i=1; i<n; i++){
		for(int j=i-1; j>=0; j--){
			while(arr[j]>arr[i]){
				a[j+1]=a[j];
				j=j-1	
			}
		a[j+1] = a[i]; 
		}
	}
	return 0;

}
