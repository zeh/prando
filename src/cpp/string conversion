#include <iostream>
#include <string>
using namespace std;
int main(){
     string s;
     cout<<"enter the string :"<<endl;
     cin>>s;

     for (int i=0;i<s.length();i++){
        if ('a'<=s[i] && s[i]<='z'){
           s[i]=char(((int)s[i])-32);
        }

        if ('A'<=s[i] && s[i]<='Z'){
           s[i]=char(((int)s[i])+32);
        }
      }

     cout<<"modified string is  : "<<s<<endl;
     return 0;
}
