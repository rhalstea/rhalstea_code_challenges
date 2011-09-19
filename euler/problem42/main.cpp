#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

std::vector<int> tri_nums;

bool isTri(std::string s)
{
   int num = 0;

   for(int i = 0; i < s.size(); ++i)
      num += (int)s[i] - 64;

   if(num > tri_nums.back())
      std::cout << "problem" << std::endl;

   for(int i = 0; i < tri_nums.size(); ++i)
      if(num == tri_nums[i])
         return true;

   return false;
}

int main()
{
   std::ifstream file;
   std::string toParse;
   std::vector< std::string > words;

   file.open("words.txt");
   file >> toParse;

   char *tok = strtok((char *)toParse.c_str(), ",");
   
   while(tok != NULL)
   {
      std::string s = tok;
      words.push_back( s.substr(1,s.size()-2) );
      tok = strtok(NULL, ",");
   }

   tri_nums.push_back(1);
   for(int i = 2; tri_nums.back() < 1000; ++i)
      tri_nums.push_back( 0.5 * i * (i+1) );

   int count = 0;

   for(int i = 0; i< words.size(); ++i)
      if(isTri(words[i]))
         ++count;

   std::cout << count << std::endl;

   return 0;
}

