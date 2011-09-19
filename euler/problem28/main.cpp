#include <iostream>

int main()
{
   long long count = 1;
   int last = 1;

   for(int i = 2; i+1 <= 1001; i += 2)
   {
      count += last + i;
      count += last + 2*i;
      count += last + 3*i;
      count += last + 4*i;

      last = last + 4*i;      
   }

   std::cout << "sum: " << count << std::endl;

   return 0;
}
