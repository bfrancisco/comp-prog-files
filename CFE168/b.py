for _ in range(int(input())):
    n = int(input())
    grid = [input() for i in range(2)]

    ans = 0
    for x in range(2): 
        for i in range(1, n-1):
            y = (x+1)%2
            if grid[x][i] == "." and grid[y][i-1] == "x" and grid[y][i+1] == "x" and grid[x][i-1] == "." and grid[x][i+1] == "." and grid[y][i] == ".":
                ans += 1
    
    print(ans)