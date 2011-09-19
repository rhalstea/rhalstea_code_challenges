#!/usr/bin/python

def same_digits(val1, val2):
   return sorted(list(val1)) == sorted(list(val2))

cubes = [str(0)];

for val in range(100, 10000):
   cube = str(val ** 3);

   if( len(cubes[0]) != len(cube) ):
      cubes = []

   cubes.append(cube)
   match = []
   for item in cubes:
      if same_digits(cube, item):
         match.append(item);

   if len(match) >= 5:
      print match[0];
      raw_input()
