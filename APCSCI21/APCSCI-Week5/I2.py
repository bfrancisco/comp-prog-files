def countOut(x, y):
    c = 0
    for addx, addy in dirs:
        R = x+addx
        C = y+addy
        if 0 <= R < n and 0 <= C < m and grid[R][C] == '.':
            c += 1
    return c

def getlow():
    for i in range(1, 5):
        if db[i] > 0:
            return i

def ex():
    print()
    for row in grid:
        print(*row, sep='')
    exit()

n, m, k = map(int, input().split())
grid = [list(input()) for i in range(n)]
dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

outdeg = [[0 for _ in range(m)] for i in range(n)]

db = {i:0 for i in range(1, 5)}
for i in range(n):
    for j in range(m):
        if grid[i][j] == '#':
            continue
        outdeg[i][j] = countOut(i, j)
        db[outdeg[i][j]] += 1
print()
for row in outdeg:
    print(*row)
while k:
    lowest = getlow()
    # mark and dfs
    for i in range(n):
        for j in range(m):
            if outdeg[i][j] < 1:
                continue
            if outdeg[i][j] == lowest:
                outdeg[i][j] = 0
                grid[i][j] = 'X'
                for addx, addy in dirs:
                    R = i + addx
                    C = j + addy
                    if 0 <= R < n and 0 <= C < m and outdeg[R][C] > 0:
                        outdeg[R][C] -= 1
                k -= 1
            if k == 0:
                ex()
    




