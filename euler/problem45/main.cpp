#include <iostream>
#include <vector>

std::vector<long long> tri;
std::vector<long long> pen;
std::vector<long long> hex;

void grow_pen(long long top)
{
   while(pen.back() < top)
   {
      long long i = pen.size();
      pen.push_back( i * (3 * i -1) / 2 );
   }
}

void grow_hex(long long top)
{
   while(hex.back() < top)
   {
      long long i = hex.size();
      hex.push_back( i * (2 * i -1) );
   }
}

int main()
{
   int count = 0;

   tri.push_back(1);
   pen.push_back(1);
   hex.push_back(1);

   for(long long i = 2; count != 2; ++i)
   {
      tri.push_back( i * (i+1) / 2 );

      grow_pen(tri.back());
      grow_hex(tri.back());

      if(tri.back() == pen.back() && tri.back() == hex.back())
      {
         ++count;
         std::cout << tri.back() << std::endl;
      }
   }

   return 0;
}
