mod = 1000000007
mx = -10000000000000

def rb(ns):
    global mx
    if (len(ns) == k):
        print(ns)
        ans = 1
        for i in ns:
            ans *= a[i]
            ans %= mod
        mx = max(mx, ans)
        return

    for i in range(n):
        if (i in ns):
            continue
        ns.append(i)
        rb(ns)
        ns.pop()
    
n, k = map(int, input().split())
a = [int(i) for i in input().split()]
ns = []
rb(ns)

print(mx % mod)

