#include <iostream>
#include <vector>

int main()
{
   int max = 200;

   std::vector<int> coins;
   coins.push_back(2);
   coins.push_back(5);
   coins.push_back(10);
   coins.push_back(20);
   coins.push_back(50);
   coins.push_back(100);
   coins.push_back(200);

   std::vector<int> val;

   val.push_back(1);
   for(int i = 1; i <= max; ++i)
      val.push_back(1);

   for(int j = 0; j < coins.size(); ++j)
   {
      for(int i = coins[j]; i <= max; ++i)
      {
         val[i] += val[i-coins[j]];
      }
   }
   for(int i = 0; i <= max; ++i)
   {
      std::cout << i << ": " << val[i] << std::endl;
   }

   return 0;
}
