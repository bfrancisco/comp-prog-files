for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [i for i in input().split()]
    zer = [0 for i in range(n)]

    sm = 0
    for i in range(n):
        z = 0
        for j in range(len(a[i])-1, -1, -1):
            if a[i][j] == '0':
                z += 1
            else:
                break
        zer[i] = z

        sm += len(a[i])
    
    zer.sort(reverse=True)
    # print(zer)

    sub = 0
    for i in range(0, n, 2):
        sub += zer[i]
    
    if (sm-sub) > m:
        print("Sasha")
    else:
        print("Anna")