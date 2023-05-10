for _ in range(int(input())):
    s = input()
    n = len(s)

    se = set(list(s))
    print(n-1 if len(se) > 1 else -1)