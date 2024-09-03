for _ in range(int(input())):
    n = int(input())

    a = []
    b = []
    for i in range(n):
        x, y = map(int, input().split())
        if y == 0:
            a.append(x)
        else:
            b.append(y)
    
    a.sort()
    b.sort()
    a.append(1e9)
    b.append(1e9)
    ans = 0

    i, j = 0, 0
    while i < len(a) and j < len(b):
        while a[i] != b[j]:
            if a[i] < b[j]:
                i += 1
            elif b[j] < a[i]:
                j += 1
        
        if a[i] == 1e9:
            break
        # print((i + len(a)-1-(i+1)), (j + len(b)-1-(j+1)))
        ans += (i + len(a)-1-(i+1)) + (j + len(b)-1-(j+1))
        i += 1
        j += 1
    for 
    print(ans)