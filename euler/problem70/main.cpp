#include <iostream>
#include <cstdlib>
#include <vector>
#include "../lib/euler_functions.h"

int main(int argc, char **argv)
{
  if (argc != 2) return -1;
  euler_functions euler;

  int size = atoi(argv[1]);
  std::vector<unsigned int> primes = euler.genPrimes(size);

  std::vector<double> totient;

  for (double d = 0.0; d < size; ++d)
    totient.push_back(d);

  for (int i = 0; i < primes.size(); ++i)
    {
      int pos = primes[i];
      totient[pos] = primes[i] -1;

      for (int j = pos*2; j < totient.size(); j += pos)
	totient[j] *= 1.0 - (1.0 / (double)primes[i]);
    }

  double min = 10.0;
  double val = 0.0;
  int ans = 0;

  for (int i = 2; i < totient.size(); ++i)
    {
      val = (double)i / totient[i];

      if (val < min && euler.isPermutation(i, (int)totient[i]))
	{
	  ans = i;
	  min = val;
	}
    }

  std::cout << "Answer is " << ans << std::endl;
  return 0;
}
