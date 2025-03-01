for n in range(5, 15):
    a = sum([i for i in range(1, n-1)])
    b = n + n-1
    print(a, b)
    print(abs(a-b))
