#include <iostream>
#include <math.h>

using namespace std;

bool powerofTwo(int);

int main()
{
    int n;
    cout<<"Insert the number"<<endl;
    cin>>n;
    bool control=powerofTwo(n);
    if(control)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

bool powerofTwo(int n)
{
    double doubleVersion=log2(n);
    int intVersion=doubleVersion;
    if((doubleVersion-intVersion)>0)
        return false;
    else
        return true;

}