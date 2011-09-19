#include <iostream>
#include <vector>
#include <sstream>

int gcd(int a, int b)
{
   if(b == 0)
      return a;

   return gcd(b, a%b);
}

void reduce(int a, int b, int &c, int &d)
{
   int _gcd = 1;

   do
   {
      _gcd = gcd(a, b);
      a /= _gcd;
      b /= _gcd;
   }while(_gcd != 1);

   c = a;
   d = b;
}

bool curious(int a, int b, int c, int d)
{
   std::vector<char> to_remove;
   std::stringstream ss1, ss2, ss3, ss4;
   std::string s1, s2, s3, s4;
   ss1 << a; ss2 << b; ss3 << c; ss4 << d;
   s1 = ss1.str(); s2 = ss2.str(); s3 = ss3.str(); s4 = ss4.str();

  if(s1.size() == 1 || s2.size() == 1)
     return false;

  if(s3.size() == 2 || s4.size() == 2)
     return false;

  char f = s3[0];
  char r;

   if(s1[0] == f)
      r = s1[1];
   else if(s1[1] == f)
      r = s1[0];
   else
      return false;

   if(r == '0')
      return false;

   if(r == s2[0] && s4[0] == s2[1])
      return true;
   if(r == s2[1] && s4[0] == s2[0])
      return true;

  return false;
}

int main()
{
   int a, b;

   reduce(49, 98, a, b);
   std::cout << a << ", " << b << std::endl;
   for(int i = 1; i < 100; ++i)
      for(int j = 1; j < 100; ++j)
      {
         if( i != j )
         {
            reduce(i, j, a, b);
            if(curious(i, j, a, b))
               std::cout << i << "/" << j << " = " << a << "/" << b << std::endl;
         }
      }

   return 0;
}
