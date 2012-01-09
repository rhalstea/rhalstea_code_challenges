#include <iostream>
#include <stdio.h>
#include <cmath>

int main()
{
   int natural = 0;

   for(int i = 1; 1; ++i)
   {
      natural += i;

      int count = 1;

      for(int j = 1; j < (int)std::sqrt(natural); ++j)
         if( (natural%j) == 0 )
            ++count;

      if(count > 250)
      {
         std::cout << natural;
         return 0;
      }
   }

   return 0;
}
