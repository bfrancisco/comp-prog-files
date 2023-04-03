for _ in range(int(input())):
    n = int(input())
    a = [[*reversed(list(bin(int(i))[2:]))] for i in input().split()]
    sz = -1
    for i in range(n):
        sz = max(sz, len(a[i]))
    
    for i in range(n):
        while len(a[i]) < sz:
            a[i].append('0')
    #print(*a, sep = '\n')
    for i in range(1, n):
        for j in range(sz):
            if a[0][j] == '0':
                continue
            if a[i][j] == '0':
                a[i][j] = '1'
                a[0][j] = '0'

    for i in range(n-1):
        for j in range(sz):
            if a[n-1][j] == '1':
                continue
            if a[i][j] == '1':
                a[i][j] = '0'
                a[n-1][j] = '1'
    
    maxx = 0
    minn = 0
    #print()
    #print(*a, sep = '\n')
    for i in range(sz):
        if a[0][i] == '1':
            minn += 2**i
        if a[n-1][i] == '1':
            maxx += 2**i
    print(maxx - minn)
            


    
    