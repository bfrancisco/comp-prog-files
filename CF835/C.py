for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = sorted(a)
    out = []
    for i in a:
        if i == b[-1]:
            out.append(i - b[-2])
        else:
            out.append(i - b[-1])
    print(*out)