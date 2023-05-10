

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(i) for i in input().split()]
    l = n*m
    if m > n:
        n, m = m, n

    ans = -1000000
    for i in range(l):
        for j in range(l):
            if (i == j):
                continue
            for k in range(l):
                if (i==k) or (j==k):
                    continue
                c = 0
                c += (a[i]-a[j])*(n*(m-1))
                c += (a[i]-a[k])*(n-1)
                if (c== 45):
                    print(a[i], a[j], a[k])
                if (i == 4 and j == 3 and k == 0):
                    print(c)

                ans = max(ans, c)
    print(ans)


                
                
