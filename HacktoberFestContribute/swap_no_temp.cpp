#include<iostream>
using namespace std;

void swap(int x,int y)
{
x = x+y;
y = x-y;
x = x-y;
cout<<"Swapped values "<<x<<" "<<y<<endl;
}
int main()
{
int a,b;
a=5;b=3;
cout<<"Values before swap "<<a<<" "<<b<<endl;
swap(a,b);
return 0;
}
