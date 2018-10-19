#include <stdio.h>

int main()
{
    int num1;
    int num2;
    int a;
    int remainder;
    int numerator;
    int denominator;

    //prompt the user to enter two number
    printf("Please enter two numbers: \n");
    scanf("%d %d", &num1, &num2);

    //to get the greater number as numerator, else the result may end up less then one
    if (num1 > num2)
    {
        numerator = num1;
        denominator = num2;
    }
    else
    {
        numerator = num2;
        denominator = num1;
    }
    remainder = numerator % denominator;
    while (remainder != 0)
    {
        numerator   = denominator;
        denominator = remainder;
        remainder   = numerator % denominator;
    }
    a = denominator;

    printf("Greatest commnan divisor of %d and %d = %d\n", num1, num2, a);

}
