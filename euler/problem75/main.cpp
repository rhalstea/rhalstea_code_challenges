#include <iostream>
#include <cmath>

#define SIZE 1500000

int count[SIZE] = {0};

bool hypotenuse_is_int(int a, int b, int &c)
{
  double tmp = sqrt(a*a + b*b);
  c = (int)tmp;

  return (double)c == tmp;
}

int main()
{
  int c = 0;
  int ans = 0;
  for (int a = 1; a <= SIZE/2; ++a)
    {
      if (a % 10000 == 0)
	std::cout << a << std::endl;

      for (int b = a; b > 0 ; --b)
	if (hypotenuse_is_int(a, b, c))
	  if ((a+b+c) < SIZE)
	    count[a+b+c]++;
    }

  for (int i = 0; i < SIZE; ++i)
    if (count[i] == 1)
      ++ans;

  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
