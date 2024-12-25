for _ in range(int(input())):
    n, m = map(int, input().split())
    R = [n for i in range(n+1)]
    for i in range(m):
        x, y = map(int, input().split())
        if x > y: x, y = y, x
        R[x] = min(R[x], y-1)
    
    for i in range(n-1, 0, -1):
        R[i] = min(R[i], R[i+1])
    
    ans = 0
    for i in range(1, n+1):
        ans += R[i] - i + 1
    
    print(ans)