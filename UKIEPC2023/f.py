n, c = map(int, input().split())
a = [int(i) for i in input().split()]
b = [0 for i in range(n*2)]
a = a+a

print(a)

t = 0
for i in range(2*n-1):
    t += a[i]
    if t >= c:
        t = 0
        b[i+1] = 1

c = [0 for i in range(2*n)]
c[0] = b[0]
for i in range(1, 2*n):
    c[i] = b[i] + c[i-1]

print(b)
print(c)

for i in range(n):
    print(c[i+n-1] - c[i], end = ' ')
print()