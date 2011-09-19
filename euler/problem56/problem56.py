#!/usr/bin/python

max_val = 0
for a in range(1, 100):
   for b in range(1, 100):
      digits = str(a**b)
      val = sum(map(int,str(digits)))

      if val > max_val:
         max_val = val

print max_val

