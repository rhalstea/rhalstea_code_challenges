#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

struct cont_fraction
{
   int root;
   int numer;
   int denom;
};

bool match(const std::vector<cont_fraction> &vec, const cont_fraction val)
{
   if(vec.empty())
      return false;

   for(int i = 0; i < vec.size() -1; ++i)
      if(vec[i].numer == val.numer && vec[i].denom == val.denom)
         return true;
   return false;
}

bool power_of_2(int val)
{
   double cmp_d = std::sqrt(val);
   int cmp_i = cmp_d;

   return (double)cmp_i == cmp_d;
}

int compute_fraction(int root)
{
   cont_fraction curr;
   std::vector<cont_fraction> chain;

   curr.root = root;
   curr.numer = 1;
   curr.denom = (int)std::sqrt(root);

   int i;
   for(i = 0; !match(chain, curr); ++i)
   {
      double numer_d = (double)curr.numer;
      double denom_d = (double)curr.denom;
      double root_d = (double)curr.root;

      double value = numer_d / ( std::sqrt(root_d) - denom_d );
      int floor = (int)value;
 
      int denom_i = curr.root - (curr.denom * curr.denom);
      int numer_i = curr.denom;

      assert(denom_i % curr.numer == 0);
      
      denom_i = denom_i / curr.numer;
      numer_i = (floor * denom_i) - numer_i;

      curr.numer = denom_i;
      curr.denom = numer_i;
      chain.push_back(curr);
   }

   return i-1;
}

int main()
{
   int count = 0;
   for(int i = 1; i <= 10000; ++i)
      if(!power_of_2(i))
      {
         if(compute_fraction(i) % 2 == 1)
            ++count;
      }

   std::cout << "Answer: " << count << std::endl;
   return 0;
}

