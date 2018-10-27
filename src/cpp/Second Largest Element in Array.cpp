#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;
	//cout<<n<<endl;
	
	
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	int largest=A[0],secondLargest=A[0];

	for(int i=1;i<n;i++){
		if(A[i]>=largest){
			secondLargest=largest;
			largest=A[i];
		}
		else if(A[i]>=secondLargest&&A[i]<largest){
			secondLargest=A[i];
		}

	}

	cout<<secondLargest<<endl;
	

}