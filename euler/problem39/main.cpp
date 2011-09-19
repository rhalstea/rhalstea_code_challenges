#include <iostream>
#include <cmath>

bool isWhole(double val)
{
   int i = (int)val;

   if((double)i == val)
      return true;

   return false;
}

int main()
{
   int p[1000] = {0};

   for(int a = 1; a < 1000; ++a)
   {
      for(int b = 1; b < 1000; ++b)
      {
         double c = sqrt(a*a + b*b);
         if(isWhole(c))
         {
            int _c = (int)c;
            int pos = a + b + c -1;
            if(pos < 1000)
               p[pos]++;
         }
      }
   }

   std::cout << "120: " << p[119] << std::endl;

   int max = 0;
   for(int i = 0; i < 1000; ++i)
   {
      if(max < p[i])
      {
         std::cout << i+1 << ": " << p[i] << std::endl;
         max = p[i];
      }
   }

   return 0;
}
