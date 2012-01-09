#include <iostream>

#define SIZE 1000

bool end(long long val)
{
  double tmp = (double)val / 1000000.0;
  long long tmp_i = (long long int)tmp;

  return tmp == (double)tmp_i;
}

int main()
{
  long long int count[SIZE] = {0};

  count[0] = 1;

  for (int i = 1; i < SIZE; ++i)
    {
      for (int j = i; j < SIZE; ++j)
	count[j] += count[j-i];

      if ( end(count[i]) )
	{
	  std::cout << "Answer: " << i << "(" << count[i] << ")" << std::endl;
	}
    }

  std::cout << "Sorry, try a larger number." << std::endl;
  return 0;
}
