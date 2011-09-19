#include <stdio.h>
#include <stdlib.h>
#include <string>

int count = 0;

void print(std::string vec)
{
   count++;
   if(count >= 999999)
   {
      printf("%07d: ", count);
      for(int i = 9; i >= 0; --i)
         printf("%c, ", vec[i]);
      printf("\n");
   }

   if(count >= 1000002)
      exit(1);
}

std::string swap(int a, int b, std::string vec)
{
   char c = vec[a];
   vec[a] = vec[b];
   vec[b] = c;

   return vec;
}

std::string perm(int val, std::string vec)
{
   if(val < 2)
   {
      print(vec);
      return swap(0, 1, vec);
   }

   for(int i = val-1; i >= 0; --i)
   {
      print(perm(val-1, vec));
      vec = swap(val, i, vec);
   }

   return perm(val-1,vec);
}

int main()
{
   //std::string vec = "9876543210";
   std::string vec = "9876543210";
   print(perm(9, vec));

   return 0;
}
