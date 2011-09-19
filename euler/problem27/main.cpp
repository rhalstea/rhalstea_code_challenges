#include <iostream>
#include <cmath>

bool isPrime(long long val)
{
   if(val < 0 )
      return false;

   for(long long i = 2; i <= (long long)sqrt(val); ++i) 
      if(val % i == 0)
         return false;

   return true;
}

long long maxPrimeRun(long long a, long long b)
{
   long long count = 0;
   while(isPrime( (count*count) + (a*count) + b)) count++;
   return count;
}

int main()
{
   int max = 0;
   for(long long a = -999; a < 1000; ++a)
   {
      for(long long b = -999; b < 1000; ++b)
      {
         int tmp = maxPrimeRun(a, b);

         if(tmp > max)
         {
            std::cout << "a: " << a 
                      << ", b: " << b 
                      << ", count: " << tmp 
                      << std::endl;

            max = tmp;
         }
      }
   }

   return 0;
}
