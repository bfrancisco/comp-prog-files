from math import ceil
for _ in range(int(input())):
    n,b,c = map(int, input().split())
    if b == 0:
        if c >= n:
            print(n)
        elif c >= n-2:
            print(n-1)
        else:
            print(-1)
    elif c >= n:
        print(n)
    else:
        print(n - ceil((n-c)/b))

