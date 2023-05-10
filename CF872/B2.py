from itertools import permutations

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(i) for i in input().split()]
    a.sort()
    print()
    zz = 0
    for p in permutations(a):
        z = 0
        t = [[0 for j in range(m)] for i in range(n)]
        for i in range(n):
            for j in range(m):
                t[i][j] = a[z]
                z+=1

        ans = 0
        for i in range(n):
            for j in range(m):
                if (i==j):
                    continue
                mn, mx = 1000000, -1000000
                for x in range(n):
                    for y in range(m):
                        mn = min(mn, t[x][y])
                        mx = max(mx, t[x][y])
                ans += (mx-mn)
        # print(ans)
        zz += 1
        if zz == 1:
            for r in t:
                print(*r)
            print(ans)