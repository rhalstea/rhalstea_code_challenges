#ifndef __POKER_HAND_H__
#define __POKER_HAND_H__

#include <iostream>
#include "card.h"

struct poker_score
{
   bool royal_flush;
   int straight_flush;
   int four_of_a_kind;
   bool full_house;
   bool flush;
   bool straight;
   int three_of_a_kind;
   int two_pair_big;
   int two_pair_small;
   int one_pair;
   int high_card[5];

   poker_score()
   {
      royal_flush = false;
      straight_flush = -1;
      four_of_a_kind = -1;
      full_house = false;
      flush = false;
      straight = false;
      three_of_a_kind = -1;
      two_pair_big = -1;
      two_pair_small = -1;
      one_pair = -1;
      for(int i = 0; i < 5; ++i)
         high_card[i] = -1;
   }

   void print()
   {
      std::cout << "RF: " << royal_flush
                << " SF: " << straight_flush
                << " 4oak: " << four_of_a_kind
                << " FH: " << full_house
                << " F: " << flush
                << " S: " << straight
                << " 3oak: " << three_of_a_kind
                << " 2P: " << two_pair_big << ", " << two_pair_small
                << " 1P: " << one_pair
                << std::endl;
   }
};

class poker_hand
{
   public:
      poker_hand()
      {
         this->num_cards = 0;
      }

      void add_card(card val)
      {
         if(this->num_cards == 5)
            return;
         
         int pos = this->num_cards -1;
         for( ; pos >= 0; --pos)
         {
            if(this->my_hand[pos].get_value() > val.get_value())
               this->my_hand[pos+1] = this->my_hand[pos];
            else
               break;
         }

         this->my_hand[pos+1] = val;

         this->num_cards++;
      }

      void print()
      {
         for(int i = 0; i < 5; ++i)
         {
            this->my_hand[i].print();
            std::cout << ", ";
         }
      }

      poker_score get_score()
      {
         poker_score ret;

         char suit = this->my_hand[0].get_suit();
         ret.flush = true;

         for(int i = 0; i < 5; ++i)
            if(my_hand[i].get_suit() != suit)
               ret.flush = false;

         int val = this->my_hand[0].get_value();
         ret.straight = true;
         for(int i = 0; i < 5; ++i, ++val)
            if(my_hand[i].get_value() != val)
               ret.straight = false;

         if(ret.flush && ret.straight)
            ret.straight_flush = my_hand[4].get_value();
         if(ret.straight_flush != -1 && my_hand[4].get_value() == 14)
            ret.royal_flush = true;

         int card_count[15] = {0};
         for(int i = 0; i < 5; ++i)
         {
            int tmp = this->my_hand[i].get_value();
            card_count[tmp]++;
         }

         for(int i = 14; i >= 0; --i)
         {
            if(card_count[i] == 4)
               ret.four_of_a_kind = i;
            if(card_count[i] == 3)
               ret.three_of_a_kind = i;
            if(card_count[i] == 2 && ret.one_pair == -1)
               ret.one_pair = i;
            else if(card_count[i] == 2)
            {
               ret.two_pair_big = ret.one_pair;
               ret.two_pair_small = i;
            }
         }

         if(ret.three_of_a_kind != -1 && ret.one_pair != -1)
            ret.full_house = true;

         for(int i = 0; i < 5; ++i)
         {
            ret.high_card[i] = my_hand[i].get_value();
         }

         return ret;
      }

   private:
      card my_hand[5];
      int num_cards;
};

#endif

