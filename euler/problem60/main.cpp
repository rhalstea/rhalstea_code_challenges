#include <iostream>
#include "../lib/euler_functions.h"
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<unsigned int> primes;
euler_functions helper;

bool remarkable(unsigned int i, unsigned int j)
{
   std::stringstream ss1, ss2;
   std::string val1, val2;
   ss1 << i; ss2 << j;
   val1 = ss1.str() + ss2.str(); 
   val2 = ss2.str() + ss1.str();

   unsigned int a = atoi(val1.c_str());
   unsigned int b = atoi(val2.c_str());

   if( !helper.binarySearch(a, primes) or !helper.binarySearch(b, primes) )
      return false;
   else
      return true;
}

void search(std::vector<unsigned int> values)
{
   for(int i = 0; i < values.size(); ++i)
   {
      for(int j = i+1; j < values.size(); ++j)
      {
         if(remarkable(values[i], values[j]))
         {
            std::cout << values[i] << " " << values[j] << std::endl;
         }
      }
   }
}

int main()
{
   std::cout << "Gen Primes ... ";
   std::cout.flush();
   primes = helper.genPrimes(100000000);
   std::cout << "done" << std::endl;

   std::vector<unsigned int> three;
   std::vector<unsigned int> seven;

   std::cout << "find remarkable ... ";
   std::cout.flush();
   for(int i = 4; primes[i] < 100000; ++i)
   {
      if(remarkable(primes[i], 3))
         three.push_back(primes[i]);
      if(remarkable(primes[i], 7))
         seven.push_back(primes[i]);
   }
   std::cout << "done" << std::endl;

   std::vector<unsigned int> res(three.size());
  
   std::cout << "find intersection ... ";
   std::cout.flush();
   set_intersection(three.begin(), three.end(), seven.begin(), seven.end(), res.begin());
   std::cout << "done" << std::endl;

   while(res.size() != 0 && res.back() == 0) res.pop_back();

   search(res);
//   for(int i = 0; i < res.size(); ++i)
//      std::cout << res[i] << " ";
//   std::cout << std::endl;

   return 0;
}

