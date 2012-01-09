#include <iostream>
#include <stdio.h>
#include <sstream>

bool isPalindrome(int val)
{
   std::stringstream ss;
   ss << val;

   std::string s = ss.str();

   for(int i = 0; i < s.size()/2; ++i)
   {
      if(s[i] != s[s.size()-1-i])
         return false;
   }

   return true;
}

int main()
{
   int max = 0;
   int val;
   for(int i = 100; i < 1000; ++i)
   {
      for(int j = i; j < 1000; ++j)
      {
         val = i*j;
         if(isPalindrome(val) && (val) > max)
            max = val;
      }
   }

   printf("max: %d\n", max);
   return 0;   
}
