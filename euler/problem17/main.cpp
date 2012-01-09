#include <iostream>

int ones[10] = {-1, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int tens[10] = {-1, 3, 6, 6, 5, 5, 5, 7, 6, 6};

int ones_place(int val)
{
   //std::cout << "\tval: " << val;
   if( val < 10 && val > 0 )
      return ones[val];

   std::cout << "Passed bad value to ones_place: " << val << std::endl;
   return 0;
}

int tens_place(int val)
{
   int o = val % 10;
   int t = val / 10;

   //std::cout << "\to: " << o << "\tt: " << t << " *** ";
   if(t == 0)
      return ones_place(o);
   else if(o == 0 && t > 0 && t < 10)
      return tens[t];
   else if(t == 1)
   {
      if(o == 1) return 6;
      if(o == 2) return 6;
      if(o == 3) return 8;
      if(o == 5) return 7;
      if(o == 8) return 8;
      return 4 + ones_place(o);
   }
   else if(t > 0 && t < 10)
      return tens[t] + ones_place(o);

   std::cout << "Passed bad value to tens_place: '" 
             << t << "' '" << o << "'"  << std::endl;
   return 0;
}

int huns_place(int val)
{
   int rem = val % 100;
   int hun = val / 100;

   //std::cout << "rem: " << rem << "\thun: " << hun << " *** ";
   if(hun == 0)
      return tens_place(rem);
   else if(rem == 0 && hun > 0 && hun < 10)
      return ones[hun] + 7;
   else if(hun > 0 && hun < 10)
      return ones[hun] + 10 + tens_place(rem);

   std::cout << "passed bad value to huns_place: '" << hun << "' '" << rem << "'" << std::endl;
   return 0;
}

int main()
{
   int sum = 0;
   for(int i = 1; i < 1000; ++i)
   {
      sum += huns_place(i);
   }

   std::cout << sum + 11 << std::endl;
   return 0;
}
