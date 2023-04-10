for _ in range(int(input())):

    n = int(input())

    a = [[0 for i in range(n)] for j in range(2)]

    a[0][0] = 2*n
    a[1][n-1] = 2*n -1

    c = 1
    for i in range(0, n, 2):
        a[1][i] = c
        c += 1
        a[0][i+1] = c
        c += 1

    for i in range(n-3, -1, -2):
        a[1][i] = c
        c += 1
        a[0][i+1] = c
        c += 1

    for i in range(2):
        print(*a[i])
