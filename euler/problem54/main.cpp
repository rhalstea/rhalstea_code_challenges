#include <iostream>
#include <cstdlib>
#include <fstream>

#include "card.h"
#include "poker_hand.h"

bool p1_wins(poker_score one, poker_score two)
{
   if(one.royal_flush) return true;
   if(two.royal_flush) return false;

   if(one.straight_flush > two.straight_flush)
      return true;
   else if(two.straight_flush != -1)
      return false;

   if(one.four_of_a_kind > two.four_of_a_kind)
      return true;
   else if(two.four_of_a_kind != -1)
      return false;

   if(one.full_house) return true;
   if(two.full_house) return false;

   if(one.flush && two.flush)
      goto HIGH_CARD;

   if(one.flush) return true;
   if(two.flush) return false;

   if(one.straight && two.straight)
      goto HIGH_CARD;

   if(one.straight) return true;
   if(two.straight) return false;

   if(one.three_of_a_kind > two.three_of_a_kind)
      return true;
   else if(two.three_of_a_kind != -1)
      return false;

   if(one.two_pair_big > two.two_pair_big)
      return true;
   if(one.two_pair_big < two.two_pair_big)
      return false;

   if(one.two_pair_small > two.two_pair_small)
      return true;
   if(one.two_pair_small < two.two_pair_small)
      return false;

   if(one.one_pair > two.one_pair)
      return true;
   else if(two.one_pair != -1)
      return false;

HIGH_CARD:

   for(int i = 4; i >= 0; --i)
      if(one.high_card[i] > two.high_card[i])
         return true;
      else if(one.high_card[i] < two.high_card[i])
         return false;

   std::cout << "Tie!!!" << std::endl;

   return false;
}

int main()
{
   std::ifstream infile;
   infile.open("poker.txt");

   int count = 0;
   while(!infile.eof())
   {
      poker_hand one, two;
      
      for(int i = 0; i < 5; ++i)
      {
         std::string tmp;
         infile >> tmp;
         card mycard(tmp.c_str());
         one.add_card(mycard);
      }

      for(int i = 0; i < 5; ++i)
      {
         std::string tmp;
         infile >> tmp;
         card mycard(tmp.c_str());
         two.add_card(mycard);
      }

      if( p1_wins(one.get_score(), two.get_score()) )
         count++;
   }

   std::cout << "Answer: " << count << std::endl;

   return 0;
}
