#include <stdlib.h>
#include <stdio.h>

void IntToBin(int num) {
   if (num > 1 ) {
      IntToBin(num>>1);
   } 
   printf("%d", num%2);
   return;
}

int main(int argc, char *argv[ ]) {
   int integer;

   if (argc == 1) {
      printf("Type an Integer:\n");
      scanf("%d", &integer);
   } else if (argc == 2) {
      integer = atoi(argv[argc-1]);
   } else {
      printf("Usage: %s [INTEGER]\n", argv[0]);
      return -1;
   }
   if (integer >= 0) { 
      IntToBin(integer);
      printf("\n");
   } else {
      printf("Invalid input.\n");
   }
   return 0;
}
