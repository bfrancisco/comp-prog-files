for _ in range(int(input())):
    n = int(input())

    a = []
    b = []
    sa = set()
    sb = set()
    for i in range(n):
        x, y = map(int, input().split())
        if y == 0:
            a.append(x)
            sa.add(x)
        else:
            b.append(x)
            sb.add(x)
    
    a.sort()
    b.sort()
    a.append(1e9)
    b.append(1e9)
    ans = 0

    # print(sa, sb)
    i, j = 0, 0

    c = []
    sc = set()
    while i < len(a) and j < len(b):
        if a[i] == 1e9 or b[j] == 1e9:
            break
        # print(a[i], b[j])
        if a[i] < b[j]:
            if b[j] + b[j] - a[i] in sa:
                ans += 1
            i += 1
        elif b[j] < a[i]:
            if a[i] + a[i] - b[j] in sb:
                ans += 1
            j += 1
        else:
            ans += (i + len(a)-1-(i+1)) + (j + len(b)-1-(j+1))
            c.append(a[i])
            sc.add(a[i])
            if a[i+1] < b[j+1]:
                i += 1
            elif a[i+1] > b[j+1]:
                j += 1
            else:
                i += 1
                j += 1
        
        # print(ans)
    
    # print(c)
    for i in range(len(c)):
        if (c[i]+2 in sc and c[i]+1 in sc):
            ans += 2

    print(ans)