n, m = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort(reverse=True)
pairs = []
db = {}
for x in a:
    db[x] = 0
for i in range(n):
    for j in range(i, n):
        pairs.append((a[i] + a[j], i+1, j+1))
        if (i == j):
            continue
        pairs.append((a[i] + a[j], j+1, i+1))
pairs.sort(reverse=True)

ans = 0
for i in range(m):
    print(pairs[i][0], a[pairs[i][1]-1], a[pairs[i][2]-1])
    ans += pairs[i][0]
    db[a[pairs[i][1]-1]] += 1
    db[a[pairs[i][2]-1]] += 1

for x in a:
    print(x, ":", db[x])
print(ans)