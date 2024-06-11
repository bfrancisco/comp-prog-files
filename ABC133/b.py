n, d = map(int, input().split())

v = [[int(j) for j in input().split()] for i in range(n)]

ans = 0 
for i in range(n):
    for j in range(i+1, n):
        sq = 0
        for k in range(d):
            sq += (v[i][k] - v[j][k])**2

        if (int(sq**(1/2)) == sq**(1/2)):
            ans += 1

print(ans)