#ifndef __EULER_FUNCTIONS_H__
#define __EULER_FUNCTIONS_H__

#include <vector>
#include <string>
#include <sstream>

class euler_functions
{
   public:
      std::vector<unsigned int> genPrimes(unsigned int max)
      {
         std::vector<unsigned int> tmp;
         std::vector<unsigned int> ret;
         
         for(unsigned int i = 0; i < max; ++i)
            tmp.push_back(0);
         
         for(unsigned int i = 2; i < max; ++i)
         {
            if(tmp[i] == 0)
               ret.push_back(i);
            for(unsigned int j = i; j < max; j += i)
               tmp[j] = 1;
         }

         return ret;
      }
      
      template <class T>
      bool binarySearch(
            T key,
            std::vector<T> vec)
      {
         int min = 0;
         int max = vec.size();
         int mid = 0;

         if(max == 0)
            return false;

         do
         {
            mid = min + (max - min) / 2;

            if(vec[mid] > key)
               max = mid -1;
            else
               min = mid +1;

         }while(vec[mid] != key && min <= max);

         return vec[mid] == key;
      }

      bool isPandigital(std::string s)
      {
         int tmp[10] = {0};

         for(int i = 0; i < s.size(); ++i)
            tmp[(int)s[i] - 48]++;

         for(int i = 0; i < 10; ++i)
            if(tmp[i] != 1)
               return false;

         return true;
      }

      bool isPandigital(long long i)
      {
         std::stringstream ss;
         ss << i;
         return isPandigital(ss.str());
      }
/*
      std::vector<std::pair<int, int> > getFactors(int val)
      {
         //std::vector<int> primes = 
      }
*/
};
/*
class big_int
{
   public:
      big_int()
      {
         this->value.push_back(0);
      }

      big_int(std::string s)
      {
         set_value(s);
      }

      big_int(int i)
      {
         std::stringstream ss;
         ss << i;
         set_value(s);
      }
   private:
      std::vector<int> value;

      void set_value(std::string s)
      {
         this->value.clear();
         for(int i = 0; i < s.size(); ++i)
         {
            int tmp = (int)s[i] - 48;
            if(tmp < 10 && tmp >= 0)
               this->value.push_back(tmp);
         }
      }
};
*/
#endif
