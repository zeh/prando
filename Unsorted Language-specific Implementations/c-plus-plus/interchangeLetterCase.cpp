#include<iostream>
#include<ctype.h>

using namespace std;

int main(){
	string str,newstr="";
	getline(cin,str);
	int len = str.length();
	for(int i=0;i<len;i++){
		if(isupper(str[i]))
			newstr += tolower(str[i]);
		else
			newstr+= toupper(str[i]);
	}
	str = newstr;
	cout<<str;
}
