for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(i) for i in input().split()]

    if m < n:
        n, m = m, n

    a.sort()
    mn = a[0]
    mx1, mx2 = a[-1], a[-2]
    # print(mn, mx1, mx2)
    ans1 = 0

    # print(mx1-mn, (n*(m-1)), mx2-mn, (n-1))
    ans1 += (mx1-mn)*(n*(m-1))
    ans1 += (mx2-mn)*(n-1)
    
    ans2 = 0
    ans2 += (a[-1]-a[0])*(n*(m-1))
    ans2 += (a[-1]-a[1])*(n-1)

    print(max(ans1, ans2))


            
