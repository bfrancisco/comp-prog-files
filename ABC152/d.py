n = int(input())
strn = str(n)
ans = 0
for x in range(1, n+1):
    if (x % 10 == 0):
        # print(x, ans)
        continue

    strx = str(x)
    fst = strx[0]
    lst = strx[-1]

    v = 0
    sz = 0
    if fst == lst:
        v = fst
        sz = 1
    else:
        v = int(lst + fst)
        sz = 2
        if (v > n):
            # print(x, ans)
            continue
    ans += 1

    while True:
        sz += 1
        if (sz==2):
            v = int(lst+fst)
        else:
            v = int(lst + '0'*(sz-2) + fst)
        
        if (sz < len(strn)):
            ans += 10**(sz-2)
        
        else:
            if (int(fst) < int(lst)):
                break
            if (v > n):
                break
            if (sz == 2):
                ans += 1
                break
            if (int(lst) < int(strn[0])):
                ans += 10**(sz-2)
                break
            if (int(fst) < int(lst)):
                break
            for i in range(1, len(strn)-1):
                ans += int(strn[i]) * 10**(len(strn)-2-i)
            
            break
    # print(x, ans)

print(ans)
