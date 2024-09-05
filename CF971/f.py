for _ in range(int(input())):
    n, q = map(int, input().split())
    a = [int(i) for i in input().split()]

    b = [0]
    for i in range(n):
        b.append(b[-1] + a[i])
    for i in range(n):
        b.append(b[-1] + a[i])

    # print(b)
    for z in range(q):
        l, r = map(int, input().split())
        l -= 1 
        r -= 1
        ans = 0
        
        lt = l//n + 1 + (l%n)
        ltn = (lt + (n-(l%n)) if l%n else lt)
        lsum = b[ltn-1] - b[lt-1]
        # print(lt, ltn, lsum)

        rt = r//n + 1 + (r%n)
        rtn = (rt - (r%n) - 1 if r%n != n-1 else rt)
        rsum = b[rt] - b[rtn]
        # print(rt, rtn, rsum)

        if l//n != r//n:
            nr = (r-(r%n)-1) if rsum > 0 else r
            nl = (l+(n-(l%n))) if lsum > 0 else l
            # print(f"n, {nr} {nl}")
            ans = lsum + rsum + b[n]*(nr - nl + 1)//n
        else:
            ans = b[n] - (b[n] - lsum if lsum > 0 else 0) - (b[n] - rsum if rsum > 0 else 0)
        # print(l, r)
        print(ans)