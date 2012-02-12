#include <iostream>
#include <cmath>
#include "Primes.h"

using namespace projecteuler;

Primes p(100000);

bool is_prime(unsigned long long val) {
  int stop = (int)std::sqrt(val) + 1;

  for (int i = 0; p[i] <= stop; ++i) {
    if (val % p[i] == 0)
      return false;
  }

  return true;
}

bool is_below_10_percent(int numer, int denom) {

  double percent = (double)numer / (double)denom;
  percent *= 100;

  if ( (int)percent < 10 )
    return true;
  return false;
}

int main() {
  int num = 1;
  int side = 0;
  int prime_count = 0;
  int total_count = 1;

  do {
    side += 2;
    num += side;

    for (int i = 0; i < 4; ++i) {
      int consider = num + side * i;
      if (is_prime(consider))
	prime_count++;
    }

    num += side * 3;
    total_count += 4;
  } while( !is_below_10_percent(prime_count, total_count) );

  std::cout << "Answer: " << side + 1 << std::endl;
  return 0;
}
