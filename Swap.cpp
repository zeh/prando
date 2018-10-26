#include <iostream.h>
using namespace std;

int main()
{
	int a, b;
	cout<<"Enter two numbers : ";
	cin>>a>>b;
	a = a + b;
	b = a - b;
	a = a - b;
	cout<<"Now the first number is "<<a<<" and second number is "<<b<<" .\n";
}
