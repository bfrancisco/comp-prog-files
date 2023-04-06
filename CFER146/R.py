from math import gcd

def f(n):
    i = 1
    ls = []
    while i*i <= n:
        if n%i == 0:
            if (n//i == i):
                ls.append(i)
            else:
                ls.append(i)
                ls.append(n//i)
        i += 1
    return ls


for _ in range(int(input())):
    a,b = map(int, input().split())
    
    A, B = f(a), f(b)

    ans = a+b
    for i in A:
        for j in B:
            if(i > j):
                continue
            val = i
            val += a//i - 1
            val += j-i
            val += b//j

            ans = min(ans,val)
            # if (ans == 6):
            #     print(i, j)

    for i in B:
        for j in A:
            if(i > j):
                continue
            val = i
            val += a//i - 1
            val += j-i
            val += b//j

            ans = min(ans,val)
    print(ans)