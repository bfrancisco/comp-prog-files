for _ in range(int(input())):
    n, x = map(int, input().split())
    val = n
    m = n
    while val != x:
        val &= m
        m += 1
    
    print(m)
    