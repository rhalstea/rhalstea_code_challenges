#include <iostream>
#include <cstdlib>

int main()
{
   std::string num_a[100];

   for(int i = 0; i < 100; ++i)
      std::cin >> num_a[i];

   unsigned long long carryout = 0;
   unsigned long long sum, tmp;
   unsigned long long last5;

   for(int pos = 45; pos >= 0; pos -= 5)
   {
      sum = 0;

      for(int j = 0; j < 100; ++j)
      {
         tmp = atoi(num_a[j].substr(pos, 5).c_str());
         sum += tmp;
      }

      sum += carryout;
      carryout = sum % 100000;

      if(pos == 5)
         last5 = sum / 100000;
   }

   std::cout << sum << " " << last5 << std::endl;
   return 0;
}
