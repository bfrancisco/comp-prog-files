from collections import deque

n, m, k = map(int, input().split())
grid = [list(input()) for i in range(n)]
dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

ref = [[0 for _ in range(m)] for i in range(n)]
free = 0
x = -1
y = -1
for i in range(n):
    for j in range(m):
        if grid[i][j] == '.':
            free += 1
            x, y = i, j
        else:
            ref[i][j] = 2

# place 1 (free - k) times. 
# 0 : 'X', 1 : '.' , 2 : '#'
db = {0:'X', 1:'.', 2:'#'}
q = deque([(x, y)])
cons = free - k
vis = set()
vis.add((x, y))
while q:
    r, c = q.popleft()
    #print(r, c)
    ref[r][c] = 1
    for addx, addy in dirs:
        R = r + addx
        C = c + addy
        if 0 <= R < n and 0 <= C < m and ref[R][C] == 0 and (R,C) not in vis:
            q.append((R, C))
            vis.add((R, C))
    cons -= 1
    if cons == 0:
        break

for i in range(n):
    for j in range(m):
        print(db[ref[i][j]], end='')
    print()
