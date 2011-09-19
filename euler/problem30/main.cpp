#include <iostream>
#include <cmath>

long long sumOfPowers(long long val, int digit)
{
   if(digit == 0)
      return (long long)pow(val% 10, 5);

   long long top = val / (long long)pow(10, digit);
   long long tmp = val % (long long)pow(10, digit);

   return (long long)pow(top, 5) + sumOfPowers(tmp, digit-1);
}

int main()
{
   long long count = 0;
   for(long long i = 2; i <= 999999; ++i)
   {
      if(i == sumOfPowers(i, 10))
      {
         count += i;
         std::cout << i << std::endl;
      }
   }

   std::cout << "sum: " << count << std::endl;
   return 0;
}
