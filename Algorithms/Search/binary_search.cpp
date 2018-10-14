#include<iostream>
#include<algorithm>
using namespace std;

// RETURNS -1 IF ELEMENT IS NOT FOUND
// RETURNS POSITION OF THE ELEMENT IF PRESENT
long long int binary_search(long long int *arr,long long int size,long long int element){
	long long int s=0,e=size-1;
	while(s<=e){
		long long int mid=(s+e)/2;
		if(arr[mid]==element){
			return mid;
		}
		else if(arr[mid]>element){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return -1;
}

int main()
{
	long long int n;
	cout<<"Enter the number of elements in the array: ";
	cin>>n;

	// CREATING AN ARRAY OF SIZE N DYNAMICALLY
	long long int *arr=new long long int[n];

	//TAKING INPUT FOR THE ARRAY
	for(long long int i=0;i<n;i++){
		cin>>arr[i];
	}

	//TAKE THE ELEMENT TO SEARCH FOR AS INPUT
	long long int element;
	cout<<"Enter the element to search: ";
	cin>>element;

	long long int pos=binary_search(arr,n,element);
	if(pos!=-1){
		cout<<"Element found at position: "<<pos<<endl;
	}
	else{
		cout<<"Element not found."<<endl;
	}
}