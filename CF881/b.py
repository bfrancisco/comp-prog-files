for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    c = 0
    neg = False
    for x in a:
        if x == 0: continue
        elif x < 0:
            if not neg: c += 1
            neg = True
        else:
            neg = False
    
    print(sum([abs(x) for x in a]), c)