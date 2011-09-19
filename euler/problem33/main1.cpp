#include <iostream>
#include <sstream>
#include <cstdlib>
bool curious(int a, int b)
{
   std::stringstream ss1, ss2;
   ss1 << a; ss2 << b;
   std::string s1 = ss1.str(), s2 = ss2.str();

   if(s1.size() == 1)
      return false;

   if(s1[1] == '0' && s2[1] == '0')
      return false;

   for(int i = 0; i < s1.size(); ++i)
   {
      for(int j = 0; j < s2.size(); ++j)
      {
         float tmp = (float)a / (float)b;
         float tmp1 = atof(s1.substr(i,1).c_str()) / atof(s2.substr(j, 1).c_str());
         if(tmp == tmp1)
         {
            if( s1[ (i+1)%2 ] == s2[ (j+1)%2 ] )
            {
               std::cout << a << "/" << b << " = " << s1[i] << "/" << s2[j] << std::endl;
               return true;
            }
         }
      }
   }
   return false;
}

int main()
{
   for(int i = 1; i < 100; ++i)
      for(int j = i; j < 100; ++j)
         if( i != j)
            curious(i, j);

   return 0;
}
