#include<iostream>
#include<string>

using namespace std;

int main(){
	string target, rm;
	getline(cin,target);
	getline(cin,rm);
	int len=rm.length();
	int pos;
	while(1){
		pos = target.find(rm);
		if(pos == string::npos)
			break;
		target.replace(pos,len,"");
	}
	cout<<target;
	return 0;
}
