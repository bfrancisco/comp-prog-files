for _ in range(int(input())):
    n, s, r = map(int, input().split())

    a = [0 for i in range(n)]
    i = 0
    while s:
        # print(i)
        if s-6 >= 0:
            a[i] = 6
            s -= 6
        elif s-5 >= 0:
            a[i] = 5
            s -= 5
        elif s-4 >= 0:
            a[i] = 4
            s -= 4
        elif s-3 >= 0:
            a[i] = 3
            s -= 3
        elif s-2 >= 0:
            a[i] = 2
            s -= 2
        elif s-1 >= 0:
            a[i] = 1
            s -= 1
        i += 1

    j = 0
    while i < n and a[i] == 0:
        a[j] -= 1
        a[i] += 1
        i += 1
        if (a[j] == 1):
            j += 1
    
    print(*a)

