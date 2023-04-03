import bisect
from math import sqrt
def hasnoroot(a,b,c):
    if (b**2 - (4*a*c) < 0):
        return True
    else:
        return False

for _ in range(int(input())):
    n, m = map(int, input().split())

    q = []
    for i in range(n):
        q.append(int(input()))
    q.sort()
    for j in range(m):
        a,b,c = map(int, input().split())
        i = bisect.bisect_left(q, b)
        pas = False
        j = i-2
        for k in range(j, j+4):
            if (j < 0 or j > n):
                continue
            if hasnoroot(a, b-q[j], c):
                print("YES")
                print(q[j])
                pas = True
                break
        
        if not pas:
            print("NO")
        
        