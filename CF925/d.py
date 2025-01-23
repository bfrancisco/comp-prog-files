for _ in range(int(input())):
    n, x, y = map(int, input().split())
    a = [int(i) for i in input().split()]

    db = {}
    ans = 0
    for e in a:
        ex, ey = (x-(e%x))%x, e%y

        if (ex, ey) in db:
            ans += db[(ex, ey)]

        if (e%x, ey) not in db:
            db[(e%x, ey)] = 1
        else:
            db[(e%x, ey)] += 1

    print(ans)

