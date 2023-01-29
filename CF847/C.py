for _ in range(int(input())):
    n = int(input())
    db = {}
    for i in range(1, n+1):
        x = [int(i) for i in input().split()]
        for j in range(len(x)):
            # print(j)
            if x[j] not in db:
                db[x[j]] = [j, j]
            else:
                db[x[j]][0] = min(j, db[x[j]][0])
                db[x[j]][1] = max(j, db[x[j]][1])

    a = []
    for k, v in db.items():
        a.append([v[0], v[1], k])
    
    a.sort()

    for i in range(n):
        print(a[i][2], end = ' ')
        

