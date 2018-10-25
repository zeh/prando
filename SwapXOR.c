#include <stdio.h>

int main(int argc, char *argv[ ]) {
   int a, b;

   printf("Type two integers:\n");
   scanf("%d %d", &a, &b);

   printf("Before Swap: A = [%d], B = [%d]\n", a, b);
   a ^= b ^= a ^= b;
   printf("After Swap: A = [%d], B = [%d]\n", a, b);

   return 0;
}
