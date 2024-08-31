for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(i) for i in input().split()]

    cur = max(a)
    for _ in range(m):
        op, l, r = input().split()
        l, r = int(l), int(r)
        if op == '+':
            if l <= cur and cur <= r:
                cur += 1
        else:
            if l <= cur and cur <= r:
                cur -= 1

        print(cur, end=' ')
    print()