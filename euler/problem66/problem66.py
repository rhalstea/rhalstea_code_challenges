#!/usr/bin/python
import math

def isSquare(number):
   tmp = math.sqrt(int(number))
   return not (round(tmp) != tmp)

def isWhole(number):
   return not(round(number) != number)

for D in range(2, 66):
   if isSquare(D):
      continue

   x = 0.5
   y = 0.0
   while( not isWhole(x) ):
      y = y + 1.0
      val = 1 + D * y**2
      x = math.sqrt(val)

   print str(x) + "^2 - " + str(D) + "x" + str(y) + "^2 = 1"

