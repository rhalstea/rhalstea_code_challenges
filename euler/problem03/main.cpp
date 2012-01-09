#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>

int main()
{
   unsigned long long val = 600851475143;
   //unsigned long long val = 120;

   int sqrt = (int)std::sqrt(val);
   sqrt++;

   static bool* primes = (bool *)malloc(sizeof(bool) * sqrt);
   memset(primes, 0, sizeof(bool)*sqrt);

   for(unsigned i = 2; i < sqrt; ++i)
   {
      for(unsigned j = i*2; j < sqrt; j += i)
      {
         primes[j] = 1;
      }
   }

   for(unsigned i = sqrt; i > 0; --i)
   {
      if(primes[i] == 0 && val%i == 0)
      {
        printf("%d\n", i);
        return 0;
      }
   }

   printf("none\n");
   return 0;
}
