#include<bits/stdc++.h>
using namespace std;

void displayElements(vector<int> vec){
	for(auto n : vec)
		cout<<n<<" ";
    cout<<endl;
}

int secondLargestElement(vector<int> vec){
	int max1 = vec[0],max2 = INT_MIN;

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

	for(int i = 0;i<n;i++)
		cin>>vec[i];

	cout<<"Entered elements: ";
    displayElements(vec);

	cout<<"Second Largest Element of the array: "<<secondLargestElement(vec);
}
