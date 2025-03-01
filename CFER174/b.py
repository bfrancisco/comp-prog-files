for _ in range(int(input())):
    n, m = map(int, input().split())
    grid = [[int(j) for j in input().split()] for i in range(n)]

    ans = 0
    db = [0 for i in range(n*m+1)]
    for r in range(n):
        for c in range(m):
            db[grid[r][c]] = max(1, db[grid[r][c]])
            if r+1 < n:
                if grid[r+1][c] == grid[r][c]:
                    db[grid[r][c]] = 2
            if c+1 < m:
                if grid[r][c+1] == grid[r][c]:
                    db[grid[r][c]] = 2

            

    # print(db)
    ans = 0
    print(sum(db) - max(db))