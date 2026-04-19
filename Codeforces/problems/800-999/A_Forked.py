import math
def intput():
    return int(input())
r = intput()
for i in range(r):
    a,b = input().split()
    c,d = input().split()
    e,f = input().split()
    a,b,c,d,e,f = map(int,[a,b,c,d,e,f])
    out = 0
    possibilities = [(a,b),(b,a)]
    mult = [-1,1]
    for i in mult:
        for j in mult:
            for k in possibilities:
                c1 = c+k[0]*i
                d1 = d+k[1]*j
                diffX = math.fabs(c1-e)
                diffY = math.fabs(d1-f)
                if((diffX == a and diffY == b) or (diffX == b and diffY == a)):
                    out += 1
    if(a == b):
        out /= 2
    print(int(out))
