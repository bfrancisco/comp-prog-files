for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    one = a.count(1)
    zer = a.count(0)

    print(one%2, min(one, zer))