#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

bool prime(std::string s)
{
   if(s == "1" || s == "0")
      return false;

   int val = atoi(s.c_str());
   for(int i = 2; i <= (int)sqrt(val); ++i)
      if( val % i == 0)
         return false;

   return true;
}

bool trunc(int val)
{
   std::stringstream ss;
   ss << val;
   std::string s = ss.str();

   if(!prime(s))
      return false;

   for(int i = 1; i < s.size(); ++i)
   {
      if( !prime(s.substr(i, s.size()-i)) )
            return false;
            
      if( !prime(s.substr(0, i)) )
         return false;
   }

   return true;
}

int main()
{
   int count = 11;
   int sum = 0;

   for(int i = 10; count != 0; ++i)
   {
      if(trunc(i))
      {
         std::cout << i << std::endl;
         sum += i;
         count--;
      }
   }

   std::cout << "Answer: " << sum << std::endl;
   return 0;
}
