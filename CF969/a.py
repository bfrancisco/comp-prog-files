for _ in range(int(input())):
    l, r = map(int, input().split())
    if r-l+1 < 3:
        print(0)
        continue
    elif r-l+1 == 3:
        if l%2:
            print(1)
        else:
            print(0)
        continue
    print((r-l+1 + (1 if l%2 else 0))//4)