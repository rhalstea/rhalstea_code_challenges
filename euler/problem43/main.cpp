#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> primes;
long long value = 0;

void doSomething(std::string s)
{
   for(int i = 1; i < 8; ++i)
   {
      int tmp = atoi(s.substr(i,3).c_str());
      if(tmp % primes[i-1] != 0)
         return;
   }

   std::cout << s << std::endl;
   value += atoll(s.c_str());
}

std::string swap(int a, int b, std::string s)
{
   char c = s[a];
   s[a] = s[b];
   s[b] = c;
   return s;
}

std::string permutation(std::string s, int size)
{
   if(size < 2)
   {
      doSomething(s);
      return swap(0, 1, s);
   }

   for(int i = size-1; i >= 0; --i)
   {
      doSomething(permutation(s, size-1));
      s = swap(i, size, s);
   }

   return permutation(s, size-1);
}

int main()
{
   int tmp_primes[1000] = {0};
   for(int i = 2; i < 1000; ++i)
   {
      if(tmp_primes[i] == 0)
         primes.push_back(i);

      for(int j = i; j < 1000; j += i)
         tmp_primes[j] = 1;
   }

   std::string s = "0123456789";

   permutation(s, 9);

   std::cout << "Answer: " << value << std::endl;

   return 0;
}
