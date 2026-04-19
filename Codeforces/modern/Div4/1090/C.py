import sys
input = sys.stdin.readline
def solve(p):
    l = []
    for i in range(1,p+1):
        l += [i,p+1+2*i,p+2+2*i]
    print(*l,sep=" ")
for j in range(int(input())):
    l = []
    p = int(input())
    solve(p)