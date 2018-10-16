#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string str;
    cout<<"Enter a string:";
    cin>>str;
    for(int i=0;i<=str.length();i++)
    {
        if(str[i]>=97&&str[i]<=122)
            str[i]=str[i]-32;
        else
            str[i]=str[i]+32;
    }
    cout<<"String after case change is "<<str<<endl;
}