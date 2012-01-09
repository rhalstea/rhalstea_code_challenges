#include <iostream>
#include <cstdlib>

int main()
{
   std::string number;
   std::cin >> number;

   int max = 0, val = 0;

   for(int i = 0; i < number.size()-5; ++i)
   {
      val = atoi(number.substr(i+0, 1).c_str())
          * atoi(number.substr(i+1, 1).c_str())
          * atoi(number.substr(i+2, 1).c_str())
          * atoi(number.substr(i+3, 1).c_str())
          * atoi(number.substr(i+4, 1).c_str());

      if(max < val)
         max = val;
   }

   std::cout << "max: " << max << std::endl;
   return 0;
}
