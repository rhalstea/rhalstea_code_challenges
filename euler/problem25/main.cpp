#include <iostream>
#include "../lib/BigInt.h"
#include "../lib/BigInt.cpp"

int main() {

  projecteuler::BigInt x, y ,z;

  x = 1;
  y = 1;

  int i;
  for (i = 1; x.size() < 1000; ++i) {
    z = x + y;
    x = y;
    y = z;
  }

  std::cout << "Answer: " << i << std::endl;
  return 0;
}
