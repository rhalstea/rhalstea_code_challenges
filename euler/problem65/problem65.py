#!/usr/bin/python
import sys

if len(sys.argv) != 2:
   exit(-1)

SIZE = int(sys.argv[1])

frac = [2];
for i in range(SIZE/3 +1):
   frac.append(1)
   frac.append((i+1)*2)
   frac.append(1)

while len(frac) > SIZE :
   frac.pop()

numer = 1
denom = 0

while len(frac) > 0 :
   to_add = frac.pop()
   n = denom + numer * to_add
   d = numer
   numer = n
   denom = d


print sum( map(int, list(str(numer))))
