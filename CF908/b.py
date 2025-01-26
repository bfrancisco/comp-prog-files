for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    db = {}
    for e in a:
        if e not in db:
            db[e] = 1
        else:
            db[e] += 1
    

    b = [3 for i in range(n)]

    change = {}
    pad = 2
    nochange = set()
    nochangeval = set()
    for i in range(n):
        if db[a[i]] > 1 and a[i] not in nochangeval:
            b[i] = 1
            nochange.add(i)
            nochangeval.add(a[i])
            change[a[i]] = pad
            pad += 1

        if pad == 4:
            break
    
    if pad < 4:
        print(-1)
        continue
    
    # print(change)
    # print(nochange)
    for i in range(n):
        if a[i] in change and i not in nochange:
            b[i] = change[a[i]]
    
    print(*b)