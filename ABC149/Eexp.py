n, m = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort(reverse=True)

b = [a[0]]
for i in range(1, n):
    b.append(b[-1] + a[i])

print(*a)
print(*b)