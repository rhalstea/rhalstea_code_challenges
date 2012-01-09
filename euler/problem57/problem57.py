#!/usr/bin/python

def add(numer, denom, val):
   numer = numer + val * denom;
   return numer

numer = 1
denom = 2
answer = 0
for count in range(0, 999):
   numer = add(numer, denom, 2)
   numer, denom = denom, numer
   tmp = add(numer, denom, 1)
   if len(str(tmp)) > len(str(denom)) :
      answer = answer +1

print answer
