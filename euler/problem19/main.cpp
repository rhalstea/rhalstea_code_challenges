#include <iostream>

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
   int dayOfWeek = 1;
   int count = 0;
   
   for(int year = 1900; year <= 2000; ++year)
   {
      for(int month = 0; month < 12; ++month)
      {
         std::cout << dayOfWeek << std::endl;
         if(dayOfWeek == 0 and year > 1900)
            count++;

         dayOfWeek += daysInMonth[month];
         if(month == 1 && year % 4 == 0 && year != 1900)
            dayOfWeek++;

         dayOfWeek = dayOfWeek % 7;
      }
   }

   std::cout << "count: " << count << std::endl;
   return 0;
}
