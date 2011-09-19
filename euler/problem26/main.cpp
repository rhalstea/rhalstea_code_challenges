#include <iostream>
#include <vector>

int chain(int i)
{
   std::vector<int> vec;
  
   bool cycle = false;
   int ret = 0;

   int tmp = 1;
   do
   {
      if(tmp < i)
      {
         tmp = tmp * 10;
      }
      else
      {
         vec.push_back( tmp );
         tmp = tmp % i;
      }

      if(tmp == 0)
         cycle = true;

      for(int i = 0; i < vec.size(); ++i)
         if(vec[i] == tmp)
         {
            ret = vec.size() - i;
            cycle = true;
         }
   
   }while(!cycle);

   return ret;
}

int main()
{
   int max = 0;
   int pos = 0;
   for(int i = 2; i <= 1000; ++i)
   {
      int tmp = chain(i);
      if(max < tmp)
      {
         max = tmp;
         pos = i;
      }
   }

   std::cout << pos << ": " << max << std::endl;
   return 0;   
}
