#include <iostream>
#include <cstdlib>

int gcd(int a, int b)
{
  int tmp;
  while(b != 0)
    {
      tmp = b;
      b = a % b;
      a = tmp;
    }

  return a;
}

int main(int argc, char **argv)
{
  if (argc != 2) return -1;
  int size = atoi( argv[1] );


  int num_small, num_big, denom, count = 0;

  for (denom = 4; denom <= size; ++denom)
    {
      num_big = denom / 2;
      num_small = (denom / 3) + 1;

      for (int i = num_small; i <= num_big; ++i)
	{
	  if (gcd(i, denom) == 1)
	    ++count;
	}
    }

  std::cout << "Answer: " << count << std::endl;

  return 0;
}
