#!/usr/bin/python

nums = range(0,10)

count = 0

for power in range(1, 100):
   for base in nums:
      val = base ** power
      if( val > 0 and len(str(val)) == power):
         print base, "^", power, "=", val 
         count = count +1;
print count
