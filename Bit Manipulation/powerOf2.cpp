#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the number to be checked\n";
    int num;
    cin>>num;
    int res=0;
    //you can also do it by using shift operators. I have done the same thing just by using the solution given below.
    while(num!=0){
        if(num==1 && res==0){
            cout<<"Yes";
            break;
        }
        if(num%2==1){
            cout<<"No\n";
            res=1;
            break;
        }
        num=num/2;
    }
    return 0;
}

