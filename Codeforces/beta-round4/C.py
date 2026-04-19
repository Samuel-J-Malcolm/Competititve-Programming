import sys
names = {}
len = int(input())
out = ""
for i in range(len):
    name = input()
    if name in names:
        n = names[name]
        sys.stdout.write(name + str(n) + "\n")
        names[name] += 1
    else:
        sys.stdout.write("OK\n")
        names[name] = 1
