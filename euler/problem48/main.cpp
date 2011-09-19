#include <iostream>
#include <vector>
#include <cmath>

#define MAX 10

void print(std::vector<int> a)
{
   int max = MAX;
   if(a.size()-1 < max)
      max = a.size()-1;

   for(int i = max; i >= 0; --i)
      std::cout << a[i];
   std::cout << std::endl;
}

std::vector<int> add(std::vector<int> a, std::vector<int> b)
{
   std::vector<int> small, big, ret;

   if(a.size() > b.size())
   {
      big = a;
      small = b;
   }
   else
   {
      big = b;
      small = a;
   }

   int carry = 0;
   int sum;
   for(int i = 0; i < big.size(); ++i)
   {
      sum = 0;
      if(i < small.size())
         sum = small[i] + big[i] + carry;
      else
         sum = big[i] + carry;
      carry = sum / 10;
      ret.push_back(sum % 10);
   }

   if(carry != 0)
      ret.push_back(carry);

   return ret;
}

bool equal(std::vector<int> a, int b)
{
   int val = 0;
   for(int i = a.size()-1; i >= 0; --i)
      val += a[i] * (int)pow(10, i);

   return b == val;
}

std::vector<int> mult_5(std::vector<int> a, std::vector<int> b)
{
   int max = MAX;

   std::vector<int> ret;
   ret.push_back(0);

   for(int i = 0; i < a.size() && i < max; ++i)
   {
      std::vector<int> tmp;
      for(int j = 0; j < i; ++j)
         tmp.push_back(0);

      int carry = 0;
      for(int j = 0; j < b.size(); ++j)
      {
         int prod = a[i] * b[j] + carry;
         tmp.push_back(prod % 10);
         carry = prod / 10;         
      }

      if(carry != 0)
         tmp.push_back(carry);

      ret = add(ret, tmp);
   }

   while(ret.size() > max)
      ret.pop_back();

   return ret;
}

int main()
{
   std::vector<int> answer, tmp, one;
   answer.push_back(0);
   tmp.push_back(0);
   one.push_back(1);

   for(int i = 1; i <= 1000; ++i)
   {
      std::vector<int> val;
      tmp = add(tmp,one);
      val = tmp;

      for(int j = 1; j < i; ++j)
         val = mult_5(val,tmp);

      answer = add(answer, val);

      while(answer.size() > MAX)
         answer.pop_back();
   }

   print(answer);

   return 0;
}
