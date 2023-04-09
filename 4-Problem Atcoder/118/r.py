a = []

for i in range(9):
    n, m = map(int, input().split())
    a.append((m, n))
a.sort()
print(*a)