#include <iostream>
#include<conio.h>
using namespace std ;
int main()
{
char ch;
cout<<"Enter any Alphabet:";
cin>>ch;

if(ch>='a'&&ch<='z')
{
cout<<"\tYou have entered a lowercase alphabet";
ch=ch-32;
cout<<"\nThe uppercase alphabet is "<<ch;
}
else
{
cout<<"\tYou have entered an Uppercase alphabet";
ch=ch+32;
cout<<"\nThe lowercase alphabet is "<<ch;
}
getch();
}
