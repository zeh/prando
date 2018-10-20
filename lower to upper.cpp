#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
char ch;
cout<<“Enter any Alphabet:”;
cin>>ch;

if(ch>=’a’&&ch<=’z’)
{
cout<<“ntYou have entered a lowercase alphabet”;
ch=ch-32;
cout<<“nnThe uppercase alphabet is “<<ch;
}
else
{
cout<<“ntYou have entered an Uppercase alphabet”;
ch=ch+32;
cout<<“nnThe lowercase alphabet is “<<ch;
}
getch();
}
