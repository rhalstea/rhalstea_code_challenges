#include <iostream>
#include <vector>

bool search(std::vector<long long> &vec, int start, int end, long long key)
{
   if(start > end) return false;
   if(end == start)
      return vec[start] == key;

   int middle = (end - start)/2;
   middle += start;

   if(vec[middle] == key)
      return true;
   else if(vec[middle] < key)
      return search(vec, middle+1, end, key);
   else
      return search(vec, start, middle-1, key);
}

bool search_tmp(std::vector<long long> &vec, long long key)
{
   return search(vec, 0, vec.size()-1, key);
}

void build_to(std::vector<long long> &vec, long long top)
{
   while(vec.back() < top)
   {
      long long i = vec.size()+1;
      vec.push_back( i * (3*i-1) / 2 );
   }
}

int main()
{
   std::vector<long long> pentagonal;
   pentagonal.push_back(1);
   pentagonal.push_back(5);

   long long r = 10000;
   
   build_to(pentagonal, r * (3 * r -1) / 2);
   std::cout << "size: " << pentagonal.size() << std::endl;

   for(int i = 0; i < pentagonal.size(); ++i)
   {
      for(int j = 0; j < i; ++j)
      {
         int add = pentagonal[i] + pentagonal[j];
         int sub = pentagonal[i] - pentagonal[j];

         if(search_tmp(pentagonal, add) && search_tmp(pentagonal, sub))
            std::cout << i << ", " << j  << ": " << sub << std::endl;
      }
   }

   
   return 0;
}
