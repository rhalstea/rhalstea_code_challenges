#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

bool isPandigital(int cand, int lier, int prod)
{
   std::stringstream a, b, c;
   a << cand;
   b << lier;
   c << prod;

   std::string d, e, f;
   d = a.str();
   e = b.str();
   f = c.str();

   if( (d.size() + e.size() + f.size()) != 9)
      return false;

   int digits[10] = {0};

   for(int i = 0; i < d.size(); ++i)
      if(digits[ atoi(d.substr(i, 1).c_str()) ])
         return false;
      else
         digits[ atoi(d.substr(i,1).c_str()) ] = 1;

   for(int i = 0; i < e.size(); ++i)
      if(digits[ atoi(e.substr(i,1).c_str()) ])
         return false;
      else
         digits[ atoi(e.substr(i,1).c_str()) ] = 1;

   for(int i = 0; i < f.size(); ++i)
      if(digits[ atoi(f.substr(i,1).c_str()) ])
         return false;
      else
         digits[ atoi(f.substr(i,1).c_str()) ] = 1;


   if(digits[0] == 1)
      return false;
   else
      return true;
}

void addToVector(std::vector<int> &vec, int val)
{
   for(int i = 0; i < vec.size(); ++i)
      if(vec[i] == val)
         return;

   vec.push_back(val);
   return;
}

int main()
{
   std::vector<int> myVec;

   for(int i = 0; i < 10; ++i)
      for(int j = 1000; j < 10000 ; ++j)
         if(isPandigital(i, j, i*j))
             addToVector(myVec, i*j);

   for(int i = 10; i < 100; ++i)
      for(int j = 100; j < 1000 ; ++j)
         if(isPandigital(i, j, i*j))
             addToVector(myVec, i*j);

   for(int i = 100; i < 1000; ++i)
      for(int j = 10; j < 100 ; ++j)
         if(isPandigital(i, j, i*j))
             addToVector(myVec, i*j);

   int sum = 0;
   for(int i = 0; i < myVec.size(); ++i)
      sum += myVec[i];

   std::cout << "sum: " << sum << std::endl;
   return 0;
}
