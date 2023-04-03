def hasnoroot(a,b,c):
    if (b**2 - (4*a*c) < 0):
        return True
    else:
        return False

for _ in range(int(input())):
    n, m = map(int, input().split())

    hi, lo = -1000000000, 1000000000
    mid = 1000000000
    for i in range(n):
        x = int(input())
        hi = max(x, hi)
        lo = min(x, lo)
        mid = min(abs(x), mid)

    print(hi,lo,mid)
    for j in range(m):
        a,b,c = map(int, input().split())
        y = (-b)/(2*a)
        if hasnoroot(a, b-hi, c):
            print("YES")
            print(hi)
        elif hasnoroot(a, b-lo, c):
            print("YES")
            print(lo)
        elif hasnoroot(a, b-mid, c):
            print("YES")
            print(mid)
        else:
            print("NO")