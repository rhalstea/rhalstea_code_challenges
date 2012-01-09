#include <iostream>
#include <iomanip>

#define SIZE 20

int main()
{
   unsigned long long grid[SIZE][SIZE+1];

   for(unsigned int i = 0; i < SIZE+1; ++i)
   {
      for(unsigned int j = 0; j < SIZE; ++j)
      {
         if(i == 0)
            grid[j][i] = 1;
         else if(j == 0)
            grid[j][i] = grid[j][i-1] +1;
         else
            grid[j][i] = grid[j-1][i] + grid[j][i-1];
      }
   }

   std::cout << grid[SIZE-1][SIZE] << std::endl;
   return 0;
}
