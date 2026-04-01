import math,sys
a = input()
for j in range(int(a)):
    len1 = input()
    s = input().split("00")
    max = 0
    min = 0
    for i in s:
        l = len(i)
        min += math.floor(l/2+1/2)
        max += l
    print(str(min) + " " + str(max))