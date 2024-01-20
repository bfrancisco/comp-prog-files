for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    a.sort()
    b.sort()
    ans = 0
    l = 0
    r = m-1
    
    for i in range(n):
        q = abs(a[i] - b[l])
        w = abs(a[i] - b[r])
        if (q >= w):
            ans += q
            l += 1
        else:
            ans += w
            r -= 1
    
    c = []
    for i in range(n//2):
        c.append(i)
        c.append(n-i-1)
    if n%2==1:
        c.append(n//2)
    l = 0
    r = m-1
    ans2 = 0
    for i in c:
        q = abs(a[i] - b[l])
        w = abs(a[i] - b[r])
        if (q >= w):
            ans2 += q
            l += 1
        else:
            ans2 += w
            r -= 1

    ans3 = 0
    for i in range(n//2):
        ans3 += abs(a[i] - b[-1-i])
        ans3 += abs(a[-1-i] - b[i])
 
    if (n % 2 == 1):
        ans3 += max(abs(a[n//2] - b[n//2]), abs(a[n//2] - b[-1-(n//2)]))
 
    ans3 = max(ans3, sum(abs(x-y) for x, y in zip(a, reversed(b))))
    ans3 = max(ans3, sum(abs(x-y) for x, y in zip(reversed(a), b)))

    print(max(ans, ans2, ans3))