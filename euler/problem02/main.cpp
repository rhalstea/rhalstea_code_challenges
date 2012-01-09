#include <iostream>
#include <stdio.h>

int main()
{
   unsigned long long sum = 0;

   int x = 1, y = 1, z = 0;

   while(z < 4000000)
   {
      z = x + y;
      x = y;
      y = z;

      if(z%2 == 0)
      {
         printf("%d, ", z);
         sum += z;
      }
   }

   std::cout << "Sum: " << sum << std::endl;
}
