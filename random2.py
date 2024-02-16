d = 1000
bt = 16
for d in range(1, d+1):
    for i in range(1, 1 << bt):
        n = int(bin(i)[2:])
        if n % d == 0:
            print(d, n, n//d)
            break