#include <iostream>
#include <math.h>

int main()
{
   long double sumOfSquare = 0;
   long double squareOfSum = 0;

   for(long double i = 1.0; i <= 100.0; i += 1.0)
   {
      sumOfSquare += pow(i, (long double)2.0);
      squareOfSum += i;
   }

   long long int ans = pow(squareOfSum,2) - sumOfSquare;
   std::cout << "answer: " << ans << std::endl;

}
