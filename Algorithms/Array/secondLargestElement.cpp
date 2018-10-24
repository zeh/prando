#include<bits/stdc++.h>
using namespace std;

void displayElements(vector<int> vec){  // Function to display the elements
	for(auto n : vec)
		cout<<n<<" ";
	cout<<endl;
}

//This function finds the second largest element in the array in a single pass
//Returns INT_MIN in case the second largest element doesn't exist in the array
int secondLargestElement(vector<int> vec){
	int max1 = vec[0], max2 = INT_MIN;

	for(auto n : vec){
		if(n > max1){
            max2 = max1;
			max1 = n;
		}
		else if(n < max1 && n > max2){
			max2 = n;
		}
	}
	return max2;
}

int main(){
	int n;
	cin>>n;
	vector<int> vec(n);

	for(int i = 0;i < n;i++)
		cin>>vec[i];
		
	cout<<"Array elements: ";
	displayElements(vec);

	int x = secondLargestElement(vec);
    (x != INT_MIN) ? cout<<x : cout<<"Second largest element doesn't exist in the provided array."; 
}
