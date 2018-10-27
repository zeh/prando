#include<bits/stdc++.h>
using namespace std;

int count_one (int n)
        {
        	int count;
            while( n )
            {
            n = n&(n-1);
               count++;
            }
            return count;
    }
int main()
{
	int n;
	cout<<"enter the number";
	cin>>n;
	cout<<"the number of ones in binary representation of the number are "<<count_one(n);
}