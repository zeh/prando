#include <iostream>
using namespace std;
int main()
{
  int num1,num2;
  cout<<"Enter two numbers\n";
  cin>>num1>>num2;
  num1=num1+num2;
  num2=num1-num2;
  num1=num1-num2;
  cout<<"num1= "<<num1<<"\nnum2= "<<num2<<"\n";
}
