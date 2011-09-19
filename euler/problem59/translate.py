#!/usr/bin/python
import sys

text = open('cipher1.txt')

codes = text.readline().rstrip().split(",")
codes = map(int, codes)

answer = 0
for pos in range(0, len(codes)):
   if pos % 3 == 1:
      val = codes[pos] ^ 111
   elif pos % 3 == 2:
      val = codes[pos] ^ 100
   else:
      val = codes[pos] ^ 103

   answer = answer + val
   sys.stdout.write(chr(val))
print ""
print "Answer: " + str(answer)
