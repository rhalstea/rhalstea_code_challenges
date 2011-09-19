#include <iostream>
#include <cmath>

bool isSquare(double x)
{
   double d_sqrt = std::sqrt(x);
   int i_sqrt = d_sqrt;

   if( d_sqrt == i_sqrt )
      return true;
   return false;
}

bool isWhole(double d_val)
{
   int tmp = std::floor(d_val);
   if(tmp == d_val)
      return true;
   return false;
}

int main()
{
   double max_x = 3.0;
   int save_D = 2;

   for(int D = 61; D <= 61; ++D)
   {
      std::cout << "working on: " << D << std::endl;
      if(isSquare(D))
         continue;

      int x = 140022;
      while(true)
      {
         x++;
         double answer = double(x) * double(x) - 1.0;
         std::cout << "answer: " << answer << std::endl;
         answer = answer / double(D);
         std::cout << "answer: " << answer << std::endl;
         if( !isWhole(answer) )
            continue;

         double y = std::sqrt(answer);
         std::cout << "y: " << y << std::endl;
         return 0;
         if( isWhole(y) )
            break;
      }
      
      if(x > max_x)
      {
         save_D = D;
         max_x = x;
      }
   }
   return 0;
}
