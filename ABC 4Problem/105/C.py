n = 20

k = [(-2)**i for i in range(n)]




for bit in range(2**n):
    a = [0 for i in range(n)]
    b = [0 for i in range(n)]
    for i in range(n):
        if (bit & (1<<i)):
            a[i] = k[i]
            b[i] = 1
    if (b[0] == 1):
        if (sum(a) == 2):
            print(*b)
            print(sum(a))

    