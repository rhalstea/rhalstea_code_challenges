#include <iostream>
#include <vector>

#define TOP 1000000
std::vector<int> primes;

bool isPrime(int val)
{
   for(int i = 0; i < primes.size(); ++i)
      if(primes[i] == val)
         return true;
   return false;
}

int main()
{
   int tmp[TOP] = {0};

   for(int i = 2; i < TOP; ++i)
   {
      if(tmp[i] == 0)
         primes.push_back(i);
      for(int j = i; j < TOP; j += i)
         tmp[j] = 1;
   }

   int max = 1;
   for(int i = 0; primes[i] < TOP/max; ++i)
   {
      int sum = 0;
      for(int j = i; sum < TOP && j < primes.size(); ++j)
      {
         sum += primes[j];
         if(isPrime(sum) && (j-i+1) > max)
         {
            max = j - i + 1;
            std::cout << sum << ": " << max << std::endl;
         }
      }
   }

   return 0;

   for(int i = 0; i < primes.size(); ++i)
   {
      for(int start = 0; primes[start] < primes[i] / max ; ++start)
      {
         int count = 0;
         int sum = 0;
         for(int pos = start; sum < primes[i]; ++pos)
         {
            sum += primes[pos];
            count++;
         }

         if(sum == primes[i] && count > max)
         {
            std::cout << primes[i] << ": " << count << std::endl;
            max = count;
         }
      }
   }

   return 0;
}
