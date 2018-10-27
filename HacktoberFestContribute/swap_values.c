#include<stdio.h>
#include<conio.h>

int main(){
    int a,b;
    clrscr();
    printf("Enter the value of A and B\n");
    scanf("%d %d",&a,&b);

    printf("Here you add a and b as %d and %d\n",a,b);

    a=a+b;
    b=a-b;
    a=a-b;
    printf("Now,after swap ,it's value is %d and %d\n",a,b);

    getch();
    return 0;
}
