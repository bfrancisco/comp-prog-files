def solve():
    n, m = map(int, input().split())

    grid = [[0 for j in range(m)] for i in range(n)]
    revg = [[0 for j in range(m)] for i in range(n)]
    num = 1
    for i in range(n):
        for j in range(m):
            grid[i][j] = num
            num+=1
    num = 1
    for j in range(m):
        for i in range(n):
            revg[i][j] = num
            num += 1

    if (n%2 and m%2) or (n%2):
        for i in range(0, n, 2):
            print(*grid[i])
        for i in range(1, n, 2):
            print(*grid[i])

    elif m%2:
        for r in revg:
            print(*r)
    else:
        for r in grid:
            print(*r)

for i in range(int(input())):
    solve()