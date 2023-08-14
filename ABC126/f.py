while True:
    a = [int(i) for i in input().split()]
    x = 0

    for v in a:
        x ^= v
    
    print(x)