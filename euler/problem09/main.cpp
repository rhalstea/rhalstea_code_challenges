#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>

int main()
{
   int c;
   int temp;
   double square_root;

   for(int a = 1; a < 1000; ++a)
   {
      for(int b = a; b < 1000; ++b)
      {
         temp = (a*a) + (b*b);
         square_root = std::sqrt(temp);
         c = (int)square_root;

         if( (double)c != square_root)
            continue;

         if( (a+b+c) == 1000 )
         {
            printf("%d * %d * %d = %d\n", a, b, c, a*b*c);
            return 0;
         }
      }
   }

   std::cout << "didn't work" << std::endl;
   return 0;
}
