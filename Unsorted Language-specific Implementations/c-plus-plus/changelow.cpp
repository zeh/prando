#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

int main()
{char a[50];
cout<<"enter a string";
getline(cin,a);
int i=0,j;
for(i=0;a[i]!='\0';i++)
{j=a[i];
 if(j>=97 && j<=122)
 {j-=32;
 a[i]=char(j);
 }
 else
 {j+=32;
  a[i]=char(j);
 }
}
return 0;
}
