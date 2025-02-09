n, m = map(int, input().split())
grid1 = [[int(c) for c in input().split()] for r in range(n)]
grid2 = [[int(c) for c in input().split()] for r in range(n)]

vs1 = []
for R in range(n):
    r, c = R, 0
    s = set()
    while (r >= 0 and c < m):
        s.add(grid1[r][c])
        r -= 1
        c += 1
    vs1.append(s)

vs2 = []
for R in range(n):
    r, c = R, 0
    s = set()
    while (r >= 0 and c < m):
        s.add(grid2[r][c])
        r -= 1
        c += 1
    vs2.append(s)

# print(vs1)
# print(vs2)


for i in range(len(vs1)):
    if vs1 != vs2:
        print("NO")
        exit()
print("YES")