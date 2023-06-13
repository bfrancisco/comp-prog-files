n, m = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort(reverse=True)
pairs = []

for i in range(n-1):
    for j in range(i, n):
        pairs.append((a[i] + a[j], i+1, j+1))
pairs.sort(reverse=True)

for val, i, j in pairs:
    print(val, "  ", i, j)