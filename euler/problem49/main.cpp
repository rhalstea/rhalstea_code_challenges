#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

std::vector<int> primes;

bool isPrime(int val)
{
   for(int i = 0; i < primes.size(); ++i)
      if(primes[i] == val)
         return true;

   return false;
}

void swap(char &a, char &b)
{
   char c = a;
   a = b;
   b = c;
}

bool perm(int a, int b)
{
   std::stringstream ss1, ss2;
   ss1 << a;
   ss2 << b;

   int val[10] = {0};

   for(int i = 0; i < ss1.str().size(); ++i)
      val[ atoi(ss1.str().substr(i,1).c_str()) ] += 1;

   for(int i = 0; i < ss2.str().size(); ++i)
      if( val[ atoi(ss2.str().substr(i,1).c_str()) ] == 0)
         return false;
      else
         val[ atoi(ss2.str().substr(i,1).c_str()) ] -= 1;

   return true;
}

int main()
{
   int tmp[10000] = {0};

   for(int i = 2; i < 10000; ++i)
   {
      if(tmp[i] == 0 && i > 999)
         primes.push_back(i);
      for(int j = i; j < 10000; j += i)
         tmp[j] = 1;
   }

   for(int i = 0; i < primes.size(); ++i)
   {
      for(int j = i+1; j < primes.size(); ++j)
      {
         int diff = primes[j] - primes[i];
         int val = primes[j] + diff;
         if(isPrime(val) && perm(primes[i], primes[j]) && perm(primes[i], val))
         {
            std::cout << primes[i] << " " 
                      << primes[j] << " " 
                      << val << std::endl;
         }
      }

   }

   return 0;
}
