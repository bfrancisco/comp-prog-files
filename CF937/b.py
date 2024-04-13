def paint(ch, grid, r, c):
    grid[r][c] = ch
    grid[r+1][c] = ch
    grid[r][c+1] = ch
    grid[r+1][c+1] = ch

for _ in range(int(input())):
    n = int(input())
    n*=2
    grid = [[' ' for j in range(n)] for i in range(n)]
    for r in range(0, n, 2):
        for c in range(0, n, 2):
            if ((r//2+c//2)%2==0):
                paint("#", grid, r, c)
            else:
                paint(".", grid, r, c)


    for row in grid:
        print(*row, sep="")
