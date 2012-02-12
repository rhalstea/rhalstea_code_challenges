#include <iostream>
#include "BigInt.h"

using namespace projecteuler;

int main() {
  BigInt num = 1;
  for (int i = 0; i < 1000; ++i)
    num *= 2;

  int sum = 0;
  for (int i = 0; i < num.number_digits(); ++i)
    sum += num[i];

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
