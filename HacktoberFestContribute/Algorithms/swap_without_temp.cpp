#include<iostream>
using namespace std;
 
/* Function for swapping the values */
void swap(int &a, int &b)
{
    b = a + b;
    a = b - a;
    b = b - a;
}
 
int main()
{
    int a, b;
 
    cout << "Enter two numbers to be swapped : \n";
    cout <<"Enter a :\n";
    cin >> a ;
	cout <<"Enter b :\n";
	cin>> b;
    swap(a, b);
    cout << "The two numbers after swapping become :" << endl;
    cout << "Value of a : " << a << endl;
    cout << "Value of b : " << b << endl;
    return 0 ;
}
