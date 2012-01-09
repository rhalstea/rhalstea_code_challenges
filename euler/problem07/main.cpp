#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
   if(argc != 2)
      return -1;

   int max = atoi(argv[1]);
   int size = max * sizeof(bool);

   bool* primes = (bool *)malloc(size);
   memset(primes, 0, size);

   int count = 0;
   for(unsigned i = 2; i < max; ++i)
   {
      if(primes[i] == 0)
      {
         count++;
         if(count == 10001)
         {
            printf("answer: %d\n", i);
         }
      }

      for(unsigned j = i*2; j < max; j += i)
      {
         primes[j] = 1;
      }

   }

   printf("only %d primes\n", count);
   return 0;
}
