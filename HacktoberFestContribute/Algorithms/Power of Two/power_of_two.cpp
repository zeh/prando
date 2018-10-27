#include <cstdio>

int main()
{
 int number,c;
 printf("Enter a number to check if it's a power of 2!\n");
 scanf("%d",&number);
 c=number;
 while(number>2 && number%2==0)
       {
        number/=2;
       }
 printf("%d %s a power of 2\n",c,number==2?"it's":"it's not");
 return 0;
}
