#include <iostream>
#include <vector>
#include <map>

std::map<long long, long long> cache;

int main()
{
   long long max = 0;
   int pos = 0;
   std::vector<long long> stack;

   for(long long i = 1; i < 1000000; ++i)
   {
      stack.clear();

      stack.push_back(i);
      while(stack.back() != 1)
      {
         if(stack.back()%2 == 0)
            stack.push_back(stack.back()/2);
         else
            stack.push_back(3*stack.back() + 1);
      }

      if(stack.size() > max)
      {
         max = stack.size();
         pos = i;
      }
   }

   std::cout << pos << std::endl;
   return 0;
}
