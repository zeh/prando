#include<stdio.h>
#include<iostream.h>
#include<conio.h>
int arr[10] = {1,35,100,2300,45,23,2,0,89,233};
void main()
{
	int temp, size, count = 0;
	size = sizeof(arr)/sizeof(arr[0]);
	clrscr();
	for(int i=1; i<size; i++)
	{
		if(arr[i] <= arr[i-1])
		{
		    temp = arr[i-1];
		    arr[i-1] = arr[i];
		    arr[i] = temp;
		}
	}
	size--;
	for(i=1; i<size; i++)
	{
		if(arr[i] <= arr[i-1])
		{
		    temp = arr[i-1];
		    arr[i-1] = arr[i];
		    arr[i] = temp;
		}
	}
	printf("%d %d %d %d %d %d %d %d %d" 1, 35, 100, 2300, 45, 23, 2, 0, 89, 233);
	printf("\n Answer is  %d",arr[size-1]);

getch();
}
