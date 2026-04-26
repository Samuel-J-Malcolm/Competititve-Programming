import math
import sys
input = sys.stdin.readline

n = int(input())
for i in range(n):
    o = 0
    l = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if(l == 1):
        print(0)
        continue
    for i in range(l):
        a1 = a[i]
        if i == 0:
            if a1 != math.gcd(a[0],a[1]) and b[i] >= math.gcd(a[0],a[1]):
                o += 1
        elif i == l-1:
            if a1 != math.gcd(a[l-2],a[l-1])  and b[i] >= math.gcd(a[l-2],a[l-1]):
                o += 1
        else:
            if a1 != math.gcd(a[i-1],a[i]) and a1 != math.gcd(a[i],a[i+1]):
                if b[i] >= math.gcd(a[i],a[i-1]) and b[i] >= math.gcd(a[i],a[i+1]):
                    o += 1
    print(o)

