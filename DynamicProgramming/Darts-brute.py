import sys
sys.setrecursionlimit(10000)
MAX_DARTS = 4
ans = 0
n, m = [int(x) for x in input().split()]
a = [0, *(int(input()) for i in range(n))]

def rb(s):
    global ans
    if len(s) == MAX_DARTS:
        total = 0
        for i in s:
            j = int(i)
            total += a[j]
        if total <= m:
            ans = max(ans, total)
        return
    
    for i in range(n+1):
        rb(s + str(i))

rb("")
print(ans)