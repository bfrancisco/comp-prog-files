from bisect import bisect_left

for _ in range(int(input())):
    n, st = input().split()
    n = int(n)
    s = input()

    if st == 'g':
        print(0)
        continue

    gs = [0 for i in range(2*n)]
    for i in range(n):
        if s[i] == 'g':
            gs[i] = 1
    for i in range(n, 2*n):
        gs[i] = gs[i-n]

    pref = [gs[0]]
    for i in range(1, 2*n):
        pref.append(pref[i-1] + gs[i])

    ans = 0
    for i in range(n):
        if s[i] == st:
            ans = max(ans, bisect_left(pref, pref[i]+1) - i)
    print(ans)