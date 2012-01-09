#include <iostream>

#define SIZE 101

int main()
{
  long long int count[SIZE] = {0};

  count[0] = 1;

  for (int i = 1; i < SIZE; ++i)
    {
      for (int j = i; j < SIZE; ++j)
	count[j] += count[j-i];
    }


  std::cout << "Answer: " << count[SIZE -1] -1 << std::endl;
  return 0;
}
