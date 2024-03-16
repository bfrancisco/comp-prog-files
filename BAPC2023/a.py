n,m,k = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort()
sm = sum(a)

if (m == n):
    print(100)
    exit()

x = 0
for i in range(m):
    x += a[i]
