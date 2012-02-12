#include <iostream>

#include "my_helper_functions.h"
#include "Primes.h"

using namespace projecteuler;

int main() {

  Primes p(10000000);

  std::cout << "Done with primes" << std::endl;

  for (int i = p.size() -1; i >= 0; --i)
    if ( is_n_digit_pandigital(p[i]) ) {
      std::cout << "Answer: " << p[i] << std::endl;
      return 0;
    }

  return 0;
}
