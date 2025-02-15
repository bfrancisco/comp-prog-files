for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [[int(i), 0] for i in input().split()]
    b = [int(i) for i in input().split()]

    for i in range(n):
        a[i][1] = i
    a.sort()
    b.sort()

    # print(a)
    # print(b)

    ans = [0 for i in range(n)]
    for i in range(n):
        ans[a[i][1]] = b[i]

    print(*ans)        