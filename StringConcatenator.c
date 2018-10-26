#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* Concatenates a number of strings to the string given by buffer 
 * Arguments:
 *    buffer : string that will receive the concatenated strings
 *    buffsize : the size of the receiving buffer
 *    args : the number of strings to concatenate
 *    ... : a number (args) of strings to concatenate */
void concatenate(char *buffer, int buffsize, int args, ...) {
   memset(buffer, 0, buffsize); //clears the destination string
   va_list list;
   va_start(list, args); //initialize a list from stdarg.h
   for (int i = 0; i < args; i++) {
      strcat(buffer, va_arg(list, char*)); //concatenates every string
   }
   va_end(list); //releases the memory allocated
}

int main(int argc, char *argv[ ]) {
   char test[100];

   concatenate(test, 100, 5, "this ", "is ", "a ", "test", "\n");

   printf("%s", test);

   return 0; 
}
