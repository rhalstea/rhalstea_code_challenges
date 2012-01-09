#include <iostream>

int main()
{
   bool pass;
   int val = 20;
   int count = val;
   do
   {
      pass = true;
      count++;

      for(int i = 2; i <= val; ++i)
         if(count%i != 0)
            pass = false;

   }while(!pass);

   std::cout << "smallest: " << count << std::endl;
   return 0;
}
