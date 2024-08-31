n, c = map(int, input().split())
a = [int(i) for i in input().split()]
a += a
ca = [a[0]]
for i in range(1, 2*n):
    ca.append(ca[-1] + a[i])

print(a)
print(ca)

t = 0
ans
for i in range(n):
    

