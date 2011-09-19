#include <iostream>
#include <cmath>

int isSquare(int x)
{
   double d_sqrt = std::sqrt(x);
   int i_sqrt = d_sqrt;

   if( d_sqrt == i_sqrt )
      return true;
   return false;
}

int main()
{
   for(int D = 2; D <= 1000; ++D)
   {
      if(isSquare(D))
         continue;

      int x=2, y=0; 
      do {
         if(x == y) {
            x++;
            y = 0;
         }
         y++;
      }while( (x*x - D*y*y) != 1);

      std::cout << x << "^2 - " << D << "x" << y << "^2 = 1" << std::endl;
   }
   return 0;
}
