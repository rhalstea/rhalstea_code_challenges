#include <iostream>
#include <vector>



int main()
{
   int count = 0;
   std::vector<unsigned long long> comb;
   comb.push_back(1);

   while(comb.size() <= 100)
   {
      std::vector<unsigned long long> vec_tmp;
      vec_tmp.push_back(1);
      for(int pos = 1; pos < comb.size(); ++pos)
      {
         unsigned long long tmp = comb[pos-1] + comb[pos];
         vec_tmp.push_back(tmp);

         if(tmp > 1000000)
            ++count;
         if(tmp < 0)
            std::cout << "Problem: " << std::endl;
      }
      vec_tmp.push_back(1);
      comb = vec_tmp;
   }

   std::cout << "Answer: " << count << std::endl;

   return 0;
}
