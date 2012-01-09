#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
   std::vector< std::vector<int> > triangle;
   std::vector<int> temp;
   int count = 0;
   int input;

   while(std::cin >> input)
   {
      ++count;
      temp.push_back(input);

      if(count > triangle.size()){
         triangle.push_back(temp);
         temp.clear();
         count = 0;
      }
   }

   for(int i = triangle.size()-2; i >= 0; --i)
   {
      for(int j = 0; j < triangle[i].size(); ++j)
      {
         int path1 = triangle[i][j] + triangle[i+1][j];
         int path2 = triangle[i][j] + triangle[i+1][j+1];

         triangle[i][j] = (path1 > path2)? path1 : path2;
      }
   }

   std::cout << "length: " << triangle[0][0] << std::endl;
   return 0;
}
