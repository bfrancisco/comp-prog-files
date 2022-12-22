for i in range(int(input())):
    n = int(input())

    a = [int(i) for i in input().split()]
    tower = a[0]
    b = []
    for i in range(1, n):
        b.append(a[i])
    b.sort()
    #print(b)
    for x in b:
        if tower >= x:
            continue
        if (x - tower) % 2 != 0:
            tower += (x - tower)//2 + 1
        else:
            tower += (x - tower)//2
        #print(tower)
    print(tower)