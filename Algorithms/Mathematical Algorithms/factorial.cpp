#include <stdio.h>
 
int main()
{
  int n; 
 //to promopt user to enter a number.
  printf("Enter a number: \n");
  scanf("%d", &n);
 
  //It will print the number giving remainder 0.
  printf("It is divisible by: \n");
  
  int i;
  
  for (i = 2; i < n; i++)
   {
     if(n%i == 0)
        {
		 printf("%d\n", i);
		}
   }
  printf("\n");
  return 0;
}