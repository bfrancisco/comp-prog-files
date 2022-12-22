for i in range(int(input())):
    input()
    db = []
    for i in range(3):
        x, y = map(int, input().split())
        db.append((x, y))

    xc = False
    yc = False
    for i in range(3):
        x = db[i][0]
        y = db[i][1]
        for j in range(3):
            if i == j:
                continue
            x2 = db[j][0]
            y2 = db[j][1]
            if x == x2:
                xc = True
            if y == y2:
                yc = True
            
    print("NO" if xc and yc else "YES")

    

    