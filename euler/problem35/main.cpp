#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

bool prime(int val)
{
   for(int i = 2; i <= (int)sqrt(val); ++i)
      if( val % i == 0)
         return false;

   return true;
}

void swap(char &a, char &b)
{
   char c = a;
   a = b;
   b = c;
}

bool isCircularPrime(int val)
{
   std::stringstream ss;
   ss << val;
   std::string s = ss.str();

   for(int i = 0; i < s.size(); ++i)
   {
      if(!prime( atoi(s.c_str()) ) )
         return false;
      
      for(int j = s.size()-2; j >= 0; --j)
         swap(s[j], s[j+1]);

   }

   return true;
}

int main()
{
   int count = 0;
   for(int i = 2; i < 1000000; ++i)
   {
      if(isCircularPrime(i))
         ++count;
   }

   std::cout << "Answer: " << count << std::endl;
   return 0;
}
