for _ in range(int(input())):
    a = [int(i) for i in input().split()]
    b = []
    for x in a:
        b.append(x)
    b.sort()
    mx = max(a)
    if a == b and a[0] != a[1] and a[0] != a[2] and a[1] != a[2]:
        print("STAIR")
    elif mx == a[1] and a[1] != a[0] and a[1] != a[2]:
        print("PEAK")
    else:
        print("NONE")