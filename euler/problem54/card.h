#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>

class card
{
   public:
      card()
      {
         this->value = -1;
         this->suit  = ' ';
      }

      card(const char *val)
      {
         this->set_suit(val);
      }

      void set_suit(const char *val)
      {
            if(val[0] == 'A')
               value = 14;
            else if(val[0] == 'K')
               value = 13;
            else if(val[0] == 'Q')
               value = 12;
            else if(val[0] == 'J')
               value = 11;
            else if(val[0] == 'T')
               value = 10;
            else
               value = (int)(val[0] - 48);

            suit = val[1];
      }

      int get_value(){ return this->value; }
      char get_suit(){ return this->suit; }

      void print()
      {
         std::cout << this->value << this->suit;
      }
   private:
      int value;
      char suit;
};

#endif
