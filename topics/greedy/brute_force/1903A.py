def intput():
    return int(input())


for i in range(intput()):
    a,b = input().split()
    l = input().split()
    if(int(b) > 1):
        print("YES")
    else:
        l = [int(j) for j in l]
        y = True
        for i in range(0,len(l) -1):
            if(l[i+1] < l[i]):
                y= False
                print("NO")
                break
        if(y):
            print("YES")