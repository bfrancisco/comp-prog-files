from math import sqrt
N, k = map(int, input().split())
if (k > 25):
    print(N)
    exit()
ans = [1 for i in range(N)]
for d in range(2, int(sqrt(N))+1):
    dk = d**k
    if (dk > N):
       break
    for i in range(dk, N+1, dk):
        ans[i-1] = d
print(sum(ans))