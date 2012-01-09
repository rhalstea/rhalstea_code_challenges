#!/usr/bin/env python

size = 100000

count = []

for i in range(size):
    count.append(0)

count[0] = 1

for i in range(1, size):
    for j in range(i, size):
        count[j] = count[j] + count[j-i]

    if (count[i] % 1000000) == 0:
        print i, count[i]
        exit()

print "Sorry try a larger number"
        

