#include <iostream>
#include <stdio.h>
#include <cmath>

int main()
{
   double tmp;

   for(double a = 2.0; a <= 100.0; a += 1.0)
   {
      for(double b = 2.0; b <= 100.0; b += 1.0)
      {
         tmp = pow(a, b);
         printf("%0250lf\n" , tmp); //std::cout << tmp << std::endl;
      }
   }

   return 0;
}
