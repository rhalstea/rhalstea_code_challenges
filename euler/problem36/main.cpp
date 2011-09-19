#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

std::string toHex(int val)
{
   std::string buff;

   int count = 0;
   while(val > 0){++count; val <<= 1;}

   for(int i = count; i < 32; ++i)
   {
      if(val < 0)
         buff += "1";
      else
         buff += "0";

      val <<= 1;
   }
 
   return buff;
}

bool palindrone(std::string val)
{
   for(int i = 0; i < val.size()/2; ++i)
      if(val[i] != val[val.size()-1-i])
         return false;
   return true;
}

int main()
{
   int sum = 0;
   for(int i = 1; i < 1000000; ++i)
   {
      std::stringstream ss;
      ss << i;

      if( palindrone(ss.str()) && palindrone(toHex(i)) )
         sum += i;
   }

   std::cout << "sum: " << sum << std::endl;

   return 0;
}
