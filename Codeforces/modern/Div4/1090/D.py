import math
primes = [1,2,3,5,7,11]
j=13
for i in range(9995):
    for k in primes:
        if(j % k == 0):
            j += 1
            break
    primes.append(j)

def lcm(a,b):
    return a*b/math.gcd(a,b)
def prime(a):
    n=1
    for i in str(a):
        n *= primes[int(i)]
    return n 
def solve(input):
    list = [primes[i]*primes[i+1] for i in range(0,input)]
    print(*list," ")
        
for i in range(int(input())):
    solve(int(input()))