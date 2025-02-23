for _ in range(int(input())):
    R, C = map(int, input().split())
    grid = [list(input()) for i in range(R)]
    grid2 = [set() for i in range(C)]
    if C < 4:
        print("NO")
        continue

    for c in range(C):
        for r in range(R):
             grid2[c].add(grid[r][c])
    
    s = "vika"
    si = 0
    for c in range(C):
        if s[si] in grid2[c]:
            si += 1
        if si == 4:
            break
    
    # print(*grid2)
    print("YES" if si == 4 else "NO")