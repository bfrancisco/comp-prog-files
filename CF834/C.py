for _ in range(int(input())):
    l, r, x = map(int, input().split())
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a

    if a == b:
        print(0)
    elif b-a >= x:
        print(1)
    elif (a-l >= x and b-l >= x) or (r-b >= x and r-a >= x):
        print(2)
    elif (r-a >= x and b-l >= x) or (b-l >= x and r-a >= x):
        print(3)
    else:
        print(-1)
