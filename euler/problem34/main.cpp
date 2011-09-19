#include <iostream>
#include <sstream>
#include <cstdlib>

long long factorial(int val)
{
   long long tmp = 1;

   for(int i = 2; i <= val; ++i)
      tmp = i * tmp;

   return tmp;
}

bool curious(long long val)
{
   std::stringstream ss;
   ss << val;
   std::string s = ss.str();

   long long sum = 0;
   for(int i = 0; i < s.size(); ++i)
   {
      sum += factorial(atoi(s.substr(i,1).c_str()));
      if(sum > val)
         return false;
   }

   if(sum == val)
      return true;
   else
      return false;
}

int main()
{ 
   long long sum = 0;

   for(long long i = 3; i < 1000000; ++i)
   {
      if(curious(i))
      {
         std::cout << i << std::endl;
         sum += i;
      }
   }

   std::cout << "sum: " << sum << std::endl;
   return 0;
}
