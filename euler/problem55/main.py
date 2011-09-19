#!/usr/bin/python

def isPalindrome(tmp):
   word = str(tmp)
   for i in range(0, len(word)/2):
      if word[i] != word[-(i+1)] :
         return False
   return True

def isLychrel(num):
   x = num
   for i in range(0, 50):
      val = x + int(str(x)[::-1])
      if isPalindrome(val):
         return False
      else:
         x = val

   return True

count = 0

for val in range(1, 10000):
   if isLychrel(val) :
      count = count +1

print "Answer: " + str(count)

