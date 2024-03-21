from math import gcd,sqrt

for _ in range(int(input())):
    a,b,l = map(int, input().split())

    gcdA = gcd(a, l)
    gcdB = gcd(b, l)
    if (gcdA == 1 and gcdB == 1):
        print(1)
        continue
    
    expA = [1, a]
    expB = [1, b]
    while (expA[-1] < l):
        expA.append(expA[-1]*a)
    while (expB[-1] < l):
        expB.append(expB[-1]*b)

    ans = 0
    s = set()
    for A in expA:
        for B in expB:
            if (l % (A*B) == 0):
                s.add(l // (A*B))
                # print(A,B)
    print(len(s))


    