#include<iostream>
#include<string.h>
using namespace std;

void isPalindrome(string str)
{
	int l=0;
	int h=str.length()-1;
	
	while(h>l)
	{
		if(str[l++]!=str[h--])
		{
			cout<<"Not Palindrome\n";
			return;
		}
	}
	cout<<"Palindrome\n";
}

int main()
{
	isPalindrome("abba");
	isPalindrome("bacha");
	isPalindrome("neen");
}
