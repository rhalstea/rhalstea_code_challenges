#include <iostream>
#include <vector>

int main()
{
   int max = 4;
   int count = 0;

   int tmp[1000000] = {0};
   std::vector<int> primes;

   for(int i = 2; i < 1000000; ++i)
   {
      if(tmp[i] == 0)
         primes.push_back(i);

      for(int j = i; j < 1000000; j += i)
         tmp[j] = 1;
   }

   for(long long i = 3; count < max && i < primes.back(); ++i)
   {
      if(i % 1000 == 0)
         std::cout << "i: " << i << std::endl;
      int factors = 0;
      for(int j = 0; j < primes.size() && primes[j] <= i/2; ++j)
         if(i % primes[j] == 0)
            factors++;

      if(factors == max)
         count++;
      else
         count = 0;

      if(count == max)
         std::cout << "Answer: " << i - max +1 << std::endl;
   }

   std::cout << "done" << std::endl;

   return 0;
}
