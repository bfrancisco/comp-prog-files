def hasnoroot(a,b,c):
    if (b*b - (4*a*c) < 0):
        return True
    else:
        return False
 
for _ in range(int(input())):
    n, m = map(int, input().split())
 
    hi, lo = -1000000000, 1000000000 
    for i in range(n):
        x = int(input())
        hi = max(x, hi)
        lo = min(x, lo)
 
    # print(hi,lo)
    for j in range(m):
        a,b,c = map(int, input().split())
 
        if hasnoroot(a, b-hi, c):
            print("YES")
            print(hi)
        elif hasnoroot(a, b-lo, c):
            print("YES")
            print(lo)
        else:
            print("NO")