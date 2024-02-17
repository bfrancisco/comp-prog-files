N = int(input())
ans = 0
for n in range(1, N+1):
    deci = str(n)
    good = True
    for d in deci:
        if d == '7':
            good = False

    oc = n
    while (oc > 0):
        r = oc % 8
        oc = oc // 8
        if (r == 7):
            good = False

    if (good):
        ans+=1

print(ans)