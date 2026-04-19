d, g = input().split()
d = int(d)
goal = int(g)
out = ""
mins = []
maxs  = [] 
real = []
for i in range(d):
    min, max = input().split()
    mins.append(int(min))
    maxs.append(int(max))
if goal < sum(mins) or goal > sum(maxs):
    print("NO")
else:
    real = mins
    idx = 0
    while sum(real) < goal:
        real[idx] = maxs[idx]
        idx+=1
    real[idx -1] += goal-sum(real) 
    
    print("YES")
    print(*real,sep=" ")