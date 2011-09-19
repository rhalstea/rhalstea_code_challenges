#include <iostream>
#include <vector>
#include <cmath>

int main()
{
   std::vector<int> primes;
   primes.push_back(2);

   bool cont = true;
   for(int i = 3; cont; i += 2)
   {
      bool is_prime = true;
      for(int j = 2; j < i; ++j)
         if(i % j == 0)
         {
            is_prime = false;
            break;
         }

      if(is_prime)
         primes.push_back(i);
      else
      {
         bool pass = false;
         for(int j = 0; j < primes.size(); ++j)
         {
            int tmp = (i - primes[j]) / 2;
            int s = (int)sqrt(tmp);

            int tmp1 = primes[j] + 2*s*s;

            if(tmp1 == i)
            {
               pass = true;
               break;
            }
         }

         if(!pass)
         {
            std::cout << "Answer: " << i << std::endl;
            cont = false;
         }
      }
   }

   return 0;
}

