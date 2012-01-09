#include <iostream>
#include <cstdlib>
#include <vector>

int main(int argc, char **argv)
{
  if (argc != 2) return -1;
  int size = atoi(argv[1]);

  int num, denom, num_s, denom_s;
  double val;
  double max = 0.0;

  for (denom = 1; denom < size; ++denom)
    {
       num = 3 * denom / 7;
       val = (double)num / (double)denom;

       if (val > max && val != 3.0/7.0)
	 {
	   max = val;
	   num_s = num;
	   denom_s = denom;
	 }
    }

  std::cout << num_s << "/" << denom_s << std::endl;

  return 0;
}
