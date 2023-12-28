for _ in range(int(input())):
    R,C,m,k = map(int, input().split())
    if (k > min(R, C) or m > k*max(R, C) or m < k):
        print("NO")
        continue
    grid = [['.' for j in range(C)] for i in range(R)]
    for i in range(k):
        grid[i][i] = '#'
        m -= 1
    if (C >= R):
        for i in range(R):
            for j in range(C):
                if (m == 0): break
                if (grid[i][j] == '#'): continue
                grid[i][j] = '#'
                m -= 1
                
            if (m == 0): break
    elif (C < R):
        for j in range(C):
            for i in range(R):
                if (m == 0): break
                if (grid[i][j] == '#'): continue
                grid[i][j] = '#'
                m -= 1
            if (m == 0): break
    print("YES")
    for row in grid:
        print(*row, sep='')