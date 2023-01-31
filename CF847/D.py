for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    db = {}
    for x in a:
        if x not in db:
            db[x] = 1
        else:
            db[x] += 1
    a.sort(reverse=True)
    # print(*a)
    # print(db)

    val = a[0]  
    mn = float('inf')
    ans = 0
    h = 0
    i = 1
    while i < n:
        if val-1 != a[i] and val != a[i]:
            ans += mn
            while h <= i:
                if a[h] not in db:
                    h += 1
                    continue
                db[a[h]] -= mn
                if db[a[h]] == 0:
                    db.pop(a[h])
                h += 1

            mn = float('inf')
            val = a[0]
            h = 0
            i = 1

        else:
            mn = min(db[a[i]], mn)
            val = a[i]
        i += 1
    ans += mn

    print(ans)