N, M, Q = map(int, input().split())
grid = [[0 for j in range(M)] for i in range(N)]

for i in range(Q):
    a,b,c,d = map(int, input().split())
    
    for r in range(a-1, c):
        for c in range(b-1, d):
            grid[r][c] += 1


for row in grid:
    print(*row)
