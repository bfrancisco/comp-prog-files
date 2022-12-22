def ex():
    #print()
    for row in grid:
        print(*row, sep='')
    exit()
def countOut(x, y):
    c = 0
    for addx, addy in dirs:
        R = x+addx
        C = y+addy
        if 0 <= R < n and 0 <= C < m and grid[R][C] == '.':
            c += 1
    return c

n, m, k = map(int, input().split())
grid = [list(input()) for i in range(n)]
dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

mnoutdeg = 5
mncoor = (-1, -1)
mins = []
for i in range(n):
    for j in range(m):
        if grid[i][j] == '#':
            continue
        x = countOut(i, j)
        if x < mnoutdeg:
            mnoutdeg = x
            mncoor = (i, j)
            mins = [(i, j)]
        elif x == mnoutdeg:
            mins.append((i, j))

for i, j in mins:
    grid[i][j] = 'X'
    #print(i, j)
    k -= 1
    if k == 0:
        ex()
#print(k)
minset = set(mins)
stack = [mncoor]
while stack and k > 0:
    vx, vy = stack.pop()
    includ = False
    if (vx, vy) not in minset:
        grid[vx][vy] = 'X'
        includ = True
    for addx, addy in dirs:
        R = vx+addx
        C = vy+addy
        if 0 <= R < n and 0 <= C < m and grid[R][C] == '.':
            stack.append((R, C))
    
    if includ:
        k -= 1
ex()
