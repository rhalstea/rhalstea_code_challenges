#include <iostream>

int amicable[10000] = {0};

int num_div(int n)
{
   int count = 0;

   for(int i = 1; i < n; ++i)
      if(n % i == 0)
         count += i;

   return count;
}

int main()
{
   std::cout << num_div(220) << std::endl;
   std::cout << num_div(284) << std::endl;
   for(int i = 0; i < 10000; ++i)
   {
      int div_i = num_div(i);
      int div_j = num_div(div_i);

      if(div_j == i and i != div_i)
      {
         std::cout << i << " and " << div_i << std::endl;
         amicable[i] = 1;
         amicable[div_i] = 1;
      }
   }

   int sum = 0;
   for(int i = 0; i < 10000; ++i)
      if(amicable[i])
         sum += i;

   std::cout << sum << std::endl;
   return 0;
}
