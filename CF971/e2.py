def f(l, m, r):
    x = m-l+1
    if x%2==0:
        x = x//2 * (l+m)
    else:
        x = x * (l+m)//2
    y = r-m
    if y%2==0:
        y = y//2 * (m+r+1)
    else:
        y = y * (m+r+1)//2
    return x-y

for _ in range(int(input())):
    n, l = map(int, input().split())
    r = l+n-1
    L, R = l, r
    mn = 1e18
    while (r-l > 100):
        # print(l, r)
        mid = (l+r)//2
        if (f(L, mid, R) < 0):
            l = mid+1
            mn = min(mn, abs(f(L, mid+1, R)))
        elif (f(L, mid, R) >= 0):
            r = mid
        
        # print(mid, f(L, mid, R))

    for i in range(l, r+1):
        mn = min(mn, abs(f(L, i, R)))
    print(mn)
    