#include <iostream>
#include <vector>
#include "../library/euler_functions.h"

std::vector<int> tri;
std::vector<int> sqr;
std::vector<int> pen;
std::vector<int> hex;
std::vector<int> hep;
std::vector<int> oct;

euler_functions helper;

int match(int val, int mask, int start)
{
   int prefix = val % 100;
   int ret = -1, key = 0;
   if(!(mask ^ 0x0000003F))
      if( prefix == start )
         return val;
      else
         return -1;


   for(int suffix = 0; suffix < 100; ++suffix)
   {
      key = (prefix * 100) + suffix;

      if( !(mask & 0x00000001) && helper.binarySearch(key, tri) )ret = match(key, (mask | 0x00000001), start);
      if (ret >= 0 ) return ret + val; else ret = -1;

      if( !(mask & 0x00000002) && helper.binarySearch(key, sqr) )ret = match(key, (mask | 0x00000002), start);
      if (ret >= 0 ) return ret + val; else ret = -1;
      
      if( !(mask & 0x00000004) && helper.binarySearch(key, pen) )ret = match(key, (mask | 0x00000004), start);
      if (ret >= 0 ) return ret + val; else ret = -1;
      
      if( !(mask & 0x00000008) && helper.binarySearch(key, hex) )ret = match(key, (mask | 0x00000008), start);
      if (ret >= 0 ) return ret + val; else ret = -1;
      
      if( !(mask & 0x00000010) && helper.binarySearch(key, hep) )ret = match(key, (mask | 0x00000010), start);
      if (ret >= 0 ) return ret + val; else ret = -1;
      
      if( !(mask & 0x00000020) && helper.binarySearch(key, oct) )ret = match(key, (mask | 0x00000020), start);
      if (ret >= 0 ) return ret + val; else ret = -1;
   }

   return -1;
}

int main()
{
   //Generate vectors
   for(int i=1, j=1; j<10000 ; ++i, j=i*(i+1)/2)   {if(j > 999) tri.push_back(j);}
   for(int i=1, j=1; j<10000 ; ++i, j=i*i)         {if(j > 999) sqr.push_back(j);}
   for(int i=1, j=1; j<10000 ; ++i, j=i*(3*i-1)/2) {if(j > 999) pen.push_back(j);}
   for(int i=1, j=1; j<10000 ; ++i, j=i*(2*i-1))   {if(j > 999) hex.push_back(j);}
   for(int i=1, j=1; j<10000 ; ++i, j=i*(5*i-3)/2) {if(j > 999) hep.push_back(j);}
   for(int i=1, j=1; j<10000 ; ++i, j=i*(3*i-2))   {if(j > 999) oct.push_back(j);}

   int answer = -1;
   for(int i = 0; i < tri.size() && answer == -1; ++i)
      answer = match(tri[i], 1, tri[i] / 100);

   std::cout << "Answer: " << answer << std::endl;
   return 0;
}

