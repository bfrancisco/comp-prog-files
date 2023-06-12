for _ in range(int(input())):
    q = int(input())
    a = [int(i) for i in input().split()]
    prev = a[0]
    first = a[0]
    first2 = -1
    print(1, end='')
    con = 1
    for i in range(1,q):
        if con == 1:
            if a[i] >= prev:
                print(1, end='')
                prev = a[i]
            elif a[i] < prev and a[i] > first:
                print(0, end='')
            elif a[i] < prev and a[i] <= first:
                print(1, end='')
                first2 = a[i]
                prev = a[i]
                con = 2
        elif con == 2:
            if a[i] >= prev and a[i] >= first2 and a[i] <= first:
                print(1, end='')
                prev = a[i]
            else:
                print(0, end='')
    print()
