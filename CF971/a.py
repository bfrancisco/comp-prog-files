for _ in range(int(input())):
    mn = 1e9
    a, b = map(int, input().split())

    for c in range(a, b+1):
        mn = min(mn, (c-a) + (b-c))
    print(mn)