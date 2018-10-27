#include <iostream>

// Return nth fibonacci value using recursion
int fib(int n) {
  
  if(n <= 1)
    return n;

  return fib(n - 1) + fib(n - 2);
} // end function fib 

int main() {

  std::cout << fib(6) << std::endl;

  return 0;
}
