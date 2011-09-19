#!/usr/bin/python
import sys

offset = 2
text = open('cipher1.txt')

codes = text.readline().rstrip().split(",")
codes = map(int, codes)

pred = ""
for char in range(97, 123):
   good = True
   for num in codes[offset::3]:
      val = num ^ char
      if val == 127 or val < 32:
         good = False

   if good:
      pred = pred + chr(char)


for char in pred:
   print char + ": "
   for num in codes[offset::3]:
      val = num ^ ord(char)
      sys.stdout.write(chr(val))
   print ""
   print ""
   
