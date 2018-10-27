// binary to decimal converter
// limited to binary with 5 digits

#include <stdio.h>

int main()
{
	int a, b, d1, d2, d3, d4, d5;
	printf("Enter a 5 digit binary number: \n");
	scanf_s("%d", &a);
	d1 = a / 10000;
	d2 = a / 1000;
	d2 = d2 % 10;
	d3 = a / 100;
	d3 = d3 % 10;
	d4 = a / 10;
	d4 = d4 % 10;
	d5 = a % 10;

	b = d1 * 16 + d2 * 8 + d3 * 4 + d4 * 2 + d5 * 1;

	printf("%d in binary is %d in decimal\n", a, b);
}	

