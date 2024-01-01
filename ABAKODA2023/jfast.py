from math import sqrt
N, k = map(int, input().split())
if (k > 25):
    print(N)
    exit()
ans = N
db = {}
for d in range(2, int(sqrt(N))+1):
    dk = d**k
    if (dk > N):
       continue
    for i in range(dk, N+1, dk):
        if i not in db:
            ans += d-1
        else:
            ans += d - db[i]
        db[i] = d
print(ans)