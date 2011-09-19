#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

bool isPandigital(std::string val)
{
   if( val.size() !=  9)
      return false;

   int digits[10] = {0};

   for(int i = 0; i < val.size(); ++i)
      if(digits[ atoi(val.substr(i, 1).c_str()) ])
         return false;
      else
         digits[ atoi(val.substr(i,1).c_str()) ] = 1;

   if(digits[0] == 1)
      return false;
   else
      return true;
}

int main()
{
   int max = 0;

   for(int i = 1; i < 10000; ++i)
   {
      std::string tmp = "";
      for(int j = 1; tmp.size() < 10; ++j)
      {
         std::stringstream ss;
         ss << i * j;
         tmp += ss.str();

         if(isPandigital(tmp))
            if( max < atoi(tmp.c_str())) 
               max = atoi(tmp.c_str());
      }
   }

   std::cout << "Answer: " << max << std::endl;

   return 0;
}
