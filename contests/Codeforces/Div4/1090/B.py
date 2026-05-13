for i in range(int(input())):
    l = []
    l = input().split()
    for i in range(l):
        l += [i+1,l+i+1,2*l+i+1]
    print(l)