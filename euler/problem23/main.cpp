#include <iostream>
#include <cmath>
#include <vector>

bool isAbundant(int val)
{
   double middle = std::sqrt(val);
   int sum = 0;

   for(int i = 2; i <= (int)middle; ++i)
   {
      if(val%i == 0)
      {
         sum += i;
         if(i != middle) 
            sum += val/i;
      }
   }

   return (val < (sum+1))? true : false;
}

int main()
{
   std::vector<int> abund;
   int mark[28123] = {0};

   for(int i = 1; i < 28123; ++i)
      if(isAbundant(i))
         abund.push_back(i);

   for(int i = 0; i < abund.size(); ++i)
   {
      for(int j = i; j < abund.size(); ++j)
      {
         int val = abund[i] + abund[j];
         if(val < 28123)
            mark[val] = 1;
      }
   }

   long long sum = 0;
   for(int i = 0; i < 28123; ++i)
      if(mark[i] == 0)
      {
         std::cout << i << std::endl;
         sum += i;
      }

   std::cout << sum << std::endl;
   return 0;
}
