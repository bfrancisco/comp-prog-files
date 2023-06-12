for _ in range(int(input())):
    q = int(input())
    a = [int(i) for i in input().split()]
    prev = a[0]
    mn = a[0]
    print(1, end='')
    less = False
    last = -1
    for i in range(1,q):
        if (not less):
            if a[i] >= prev:
                print(1, end='')
            else:
                less = True
                print(1, end='')
                last = a[i]
                continue
            prev = a[i]
            mn = min(mn, prev)
        else:
            if a[i] > mn or a[i] < last:
                print(0, end='')
            else:
                print(1, end='')
    print()