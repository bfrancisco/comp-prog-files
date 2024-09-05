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
    while True:
        if a[i] == 1e9 or b[j] == 1e9:
            break
        # print(a[i], b[j])
        if a[i] < b[j]:
            i += 1
        elif b[j] < a[i]:
            j += 1
        else:
            ans += (i + len(a)-1-(i+1)) + (j + len(b)-1-(j+1))
            i += 1
            j += 1
        
        # print(ans)
    
    for i in range(len(a)):
        if a[i]+1 in sb and a[i]+2 in sa:
            ans += 1
    for i in range(len(b)):
        if b[i]+1 in sa and b[i]+2 in sb:
            ans += 1

    print(ans)