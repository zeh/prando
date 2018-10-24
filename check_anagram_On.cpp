#include <iostream>
#include <string>
using namespace std;

int main() {
	string a,b;
	cout<<"Enter strings a,b\n";
	cin>>a>>b;
	int count_a[128]={0},count_b[128]={0}; // arrays to count occurences of each letter;
	for(int i=0;a[i]!='\0';i++)
	count_a[a[i]]++;
	for(int j=0;b[j]!='\0';j++)
	count_b[b[j]]++;
	for(int i=0;i<128;i++)
	{
		if(count_a[i]!=count_b[i])
		{
			cout<<"Not an anagram!\n";
			return 0;
		}
	}
	cout<<"Anagram!\n";
	return 0;
}