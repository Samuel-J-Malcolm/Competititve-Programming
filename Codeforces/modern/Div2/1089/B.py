#solved during contest
import sys
input = sys.stdin.readline

def solve(x,y):
    y = [int(i.strip()) for i in y]
    max = x
    for i in range(x):
        if(y[i] > i+1):
            max -= 1
    print(max)
    pass

n = int(input())
for i in range(n):
    x = int(input())
    y = input().split()
    solve(x,y)