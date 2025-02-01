n, m = map(int, input().split())
board = [[int(j) for j in input().split()] for i in range(n)]

sortb = [[0 for j in range(m)] for i in range(n)]
for r in range(n):
    for c in range(m-1):
        if board[r][c] <= board[r][c+1]:
            sortb[r][c] = 1

# for i in range(n):
#     print(*sortb[i])


pref = [[0 for j in range(m)] for i in range(n)]

for c in range(m-1):
    pref[0][c] = sortb[0][c]

for c in range(m-1):
    for r in range(1, n):
        if sortb[r-1][c] == 1 and sortb[r][c] == 1:
            pref[r][c] = sortb[r][c] + pref[r-1][c]
        else:
            pref[r][c] = sortb[r][c]

print()
for i in range(n):
    print(*pref[i])

sts = [0 for i in range(n)]
for i in range(n):
    for j in range(m-1):
        sts[i] = max(sts[i], pref[i][j])

for i in range(n):
    print(i, ":", sts[i])

k = int(input())
for _ in range(k):
    l, r = map(int, input().split())
    l -= 1
    r -= 1
    minl = max(r - sts[r] + 1, 0)
    print("Yes" if minl <= l else "No")