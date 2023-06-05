for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    a.sort()
    s = set(a)

    if a[0] < 0:
        print(a[0])
    else:
        print(a[-1])