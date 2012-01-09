#include <iostream>
#include <vector>
#include "../lib/euler_functions.h"

#define SIZE 1000

int main()
{
  long long int count[SIZE] = {0};
  count[0] = 1;

  euler_functions euler;

  std::vector<unsigned int> primes = euler.genPrimes(SIZE);
  unsigned int val = 0;

  for (int i = 0; i < primes.size(); ++i)
    {
      val = primes[i];
      for (int j = val; j < SIZE; ++j)
	  count[j] += count[j-val];

      for (int j = 0; j <= val; ++j)
	if (count[j] > 5000)
	  {
	    std::cout << "Answer: " << j << std::endl;
	    return 0;
	  }
    }


  std::cout << "Sorry, try a larger number." << std::endl;

  return 0;
}
