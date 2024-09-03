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
    return abs(x-y)

for _ in range(int(input())):
    b, l = map(int, input().split())
    r = l+b-1
    L, R = l, r
    while (r-l >= 100):
        mid1 = l + (r - l) // 3
        mid2 = r - (r - l) // 3
        # print(f(L, mid1, R), f(L, mid1+1, R))
        # print(f(L, mid2, R), f(L, mid2+1, R))
        m1, m2 = 0,0
        if (f(L, mid1, R) < f(L, mid1+1, R)):
            m1 = 1
        elif f(L, mid1, R) > f(L, mid1+1, R):
            m1 = -1
        if (f(L, mid2, R) < f(L, mid2+1, R)):
            m2 = 1
        elif f(L, mid2, R) > f(L, mid2+1, R):
            m2 = -1

        # assert(m1!=0 or m2!=0)
        # print(l, r, " ", m1, m2)
        if (m1 == -1 and m2 == 1):
            l = mid1
            r = mid2
        elif (m1 == 1 and m2 == 1):
            r = mid1
        elif (m1 == -1 and m2 == -1):
            l = mid2
        else:
            l = mid1
            r = mid2
            
    
    mn = 1e18
    # print(l, r)
    for i in range(l, r+1):
        mn = min(mn, f(L, i, R))
    
    print(mn)

    