#include <iostream>

int main()
{
   int val_a[20][20];

   for(int row = 0; row < 20; ++row)
      for(int col = 0; col < 20; ++col)
         std::cin >> val_a[row][col];

   int max = 0;

   // right/left
   for(int row = 0; row < 20; ++row)
   {
      for(int col = 0; col < 17; ++col)
      {
         int a = val_a[row][col]
               * val_a[row][col+1]
               * val_a[row][col+2]
               * val_a[row][col+3];

         if(max < a)
            max = a;
      }
   }

   // up/down
   for(int row = 0; row < 17; ++row)
   {
      for(int col = 0; col < 20; ++col)
      {
         int a = val_a[row][col]
               * val_a[row+1][col]
               * val_a[row+2][col]
               * val_a[row+3][col];

         if(max < a)
            max = a;
      }
   }

   // down right / up left
   for(int row = 0; row < 17; ++row)
   {
      for(int col = 0; col < 17; ++col)
      {
         int a = val_a[row][col]
               * val_a[row+1][col+1]
               * val_a[row+2][col+2]
               * val_a[row+3][col+3];

         if(max < a)
            max = a;
      }
   }

   // down left / up right
   for(int row = 3; row < 20; ++row)
   {
      for(int col = 0; col < 17; ++col)
      {
         int a = val_a[row][col]
               * val_a[row-1][col+1]
               * val_a[row-2][col+2]
               * val_a[row-3][col+3];

         if(max < a)
            max = a;
      }
   }

   std::cout << max << std::endl;
   return 0;
}
