import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n = int(input())
db = {}

grid = [[0 for i in range(n+1)]]
for i in range(n):
    grid.append([0] + [int(i) for i in input().split()])

# print(grid)
for r in range(1, n+1):
    for c in range(1, n+1):
        if grid[r][c] not in db:
            db[grid[r][c]] = [set(), set()]
        
        db[grid[r][c]][0].add(r)
        db[grid[r][c]][1].add(c)

ans = 0
for rr, cc in db.values():
    ans += len(rr)*len(cc)

print(ans)
        


