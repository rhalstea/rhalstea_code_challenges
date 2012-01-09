#!/usr/bin/env python
import string

def score(name, pos):
   sum = 0;
   for c in name:
      sum +=  ord(c) - 64

   return sum*pos;

inputFile = open('names.txt')

rawdata = inputFile.read()
rawdata = string.replace(rawdata, '"', '')

names = rawdata.split(",")
names.sort()
   
count = 0
total = 0
for n in names:
   count = count +1
   total += score(n, count)

print total

