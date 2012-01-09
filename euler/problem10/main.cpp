#include <iostream>

int main()
{
   unsigned long long int sum = 0;
   int primes[2000000] = {0};

   for(int i = 2; i < 10; ++i)
   {
      if( !primes[i] )
      {
         sum += i;
      }

      for(int j = i; j < 2000000; j += i)
         primes[j] = 1;
   }

   std::cout << sum << std::endl;
   return 0;
}
