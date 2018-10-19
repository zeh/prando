#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int size;
	cout<<"Please enter the string:- "<<endl;
	string s;
	getline(cin,s);
	for(long long int i=0;i<s.size();i++)
	{
         int k=(int)s[i];
         if(k>=65&&k<=90)
         {
             s[i]=char(k+32);
         }
         else if(k>=97&&k<=122)
         {
             s[i]=char(k-32);
         }
	}
   cout<<s<<endl;
	return 0;
}