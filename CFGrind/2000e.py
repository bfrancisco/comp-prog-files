def valid(r, c, n, m):
    return 0 <= r and r < n and 0 <= c and c < m

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    w = int(input())
    a = [int(i) for i in input().split()]
    a.sort(reverse=True)
    if n > m:
        n, m = m, n
    
    grid = [[0 for i in range(m)] for j in range(n)]

    r, c = n//2, m//2
    # go spiral, L-U-R-D
    grid[r][c] = a[0]
    ai = 1
    sp = 2
    t = 0
    LU = 1
    LtoR = True
    while ai < w:
        t += 1
        # print(t, sp)

        if LU:
            if t <= sp//2:
                c -= 1
            else:
                r -= 1
                if not valid(r, c, n, m):
                    r += 1
                    break
        else:
            if t <= sp//2:
                c += 1
            else:
                r += 1
                if not valid(r, c, n, m):
                    r -= 1
                    LtoR = False
                    break
        
        
            
        grid[r][c] = a[ai]
        ai += 1

        if t == sp:
            t = 0
            sp *= 2
            LU = 1 - LU

        # for row in grid:
        #     print(*row)
        # print()
    
    LU = 1-LU
    c = m//2 + (m//2 - c) * (-1 if LU else 1)
    while True:
        grid[r][c] = a[ai]
        ai += 1

        # for row in grid:
        #     print(*row)
        # print()

        if ai == w:
            break
            
        if not LU:
            if valid(r+1, c, n, m):
                r += 1
            else:
                LU = 1-LU
                c = m//2 - (c - m//2) - (1 if LtoR else 0)
        else:
            if valid(r-1, c, n, m):
                r -= 1
            else:
                LU = 1-LU
                c = m//2 + (m//2 - c) + (1 if not LtoR else 0)
        


    # for row in grid:
    #     print(*row)
    # print()

    # preprocess sqaure
    # sliding window... weird
    


        

        
            

