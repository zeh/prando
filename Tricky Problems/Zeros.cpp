// Number Of Zeros in factorial

#include <bits/stdc++.h>
using namespace std;

int factor(int num){
	int count = 0;
	while(num %5 == 0){
		count++;
		num/=5;
	}
	return count;
}

void Zeros1(int num){
	int count = 0;
	for (int i = 5; i <= num; ++i)
	{
		/* code */
		 count += factor(i);
	}
	cout<<"No. Of Zeros by method 1 : "<<count<<endl;
}

void Zeros(int num){
	int count = 0;
	for(int i = 5; num/i ;i = i*5){
		count += num/i;
	}
	cout<<"No. Of Zeros by method 2 : "<<count<<endl;
}

int main(){
	int n;
	cin>>n;
	Zeros1(n);
	Zeros(n);
	return 0;
}