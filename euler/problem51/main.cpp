#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

#define TOP 1000000

std::vector<int> primes;

bool is_prime(std::string s)
{
   int val = atoi(s.c_str());

   int min = 0;
   int max = primes.size();
   int mid = 0;
   do
   {
      mid = min + (max - min) / 2;
      if(val > primes[mid])
         min = mid + 1;
      else
         max = mid -1;
   }while(primes[mid] != val && min <= max);

   return primes[mid] == val;
}

std::string toString(int val)
{
   std::stringstream ss;
   ss << val;

   return ss.str();
}  

int numPrimes(std::string val)
{
   int start = (val[0] == '*')? 1:0;

   int count = 0;
   for(int i = start; i < 10; ++i)
   {
      std::string tmp = val;
      for(int j = 0; j < tmp.size(); ++j)
         if(tmp[j] == '*')
            tmp[j] = (char)(i + 48);

      if(is_prime(tmp))
         count++;
   }

   return count;
}

void handlePrime(int val)
{
   std::string s = toString(val);
   
   for(int i = 0; i < 10; ++i)
   {
      std::string tmp = s;
      bool mark = false;
      for(int j = 0; j < tmp.size(); ++j)
         if(tmp[j] == (char)(i + 48))
         {
            tmp[j] = '*';
            mark = true;
         }

      if(mark && numPrimes(tmp) > 7)
         std::cout << "Answer " << val << " (" << tmp << ")" << std::endl;
   }
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

   for(int i = 0; i < primes.size(); ++i)
   {
      handlePrime(primes[i]);
   }

   return 0;
}
