#include <iostream>
#include <sstream>

int main()
{
   std::string irr = "0";

   for(int i = 1; irr.size() <= 1000000; ++i)
   {
      std::stringstream ss;
      ss << i;
      irr += ss.str();
   }

   for(int i = 1; i <= 1000000; i *= 10)
      std::cout << i << ": " << irr[i] << std::endl;

   return 0;
}
