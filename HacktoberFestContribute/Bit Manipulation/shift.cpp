#include <iostream>
// shifting ... 8 to 16 to 32 ... 
int shift(int first, int second, bool value) {

  (value == true) ? first <<= second : first >>= second;

  return first;
}

int main() {

  // shift the first integer LEFT by the second integer
  std::cout << "shift(64, 1, true) :\n";
  std::cout << shift(64, 1, true)  << std::endl;
  // shift the first integer RIGHT by the she second integer
  std::cout << "shift(64, 1, false) :\n";
  std::cout << shift(64, 1, false) << std::endl;

  return 0;
}
