#include <iostream>
#include "Primes.h"
#include "BigInt.h"

using namespace projecteuler;

int main() {

  BigInt factorial = 1;

  for (int i = 2; i <= 100; ++i)
    factorial *= i;

  std::cout << "value: " << factorial << std::endl;

  int sum = 0;
  for (int i = 0; i < factorial.size(); ++i)
    sum += factorial[i];

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
