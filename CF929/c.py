from math import gcd,sqrt

for _ in range(int(input())):
    a,b,l = map(int, input().split())

    gcdA = gcd(a, l)
    gcdB = gcd(b, l)
    if (gcdA == 1 and gcdB == 1):
        print(1)
        continue
    
    pfact = {}

    x = l
    while (x % 2 == 0):
        if (2 not in pfact):
            pfact[2] = 1
        else:
            pfact[2] += 1
        x /= 2
    
    for i in range(3, int(sqrt(x))+1, 2):
        while (n%i == 0):
            if (i not in pfact):
                pfact[i] = 1
            else:
                pfact[i] += 1
            x /= i
    if (x > 2):
        if (x not in pfact):
            pfact[int(x)] = 1
        else:
            pfact[int(x)] += 1
    
    print(pfact)
    # print()
    # print((gcdA+1)*(gcdB+1))


    