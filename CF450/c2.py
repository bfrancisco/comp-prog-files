n = int(input())
A = [int(i) for i in input().split()]
H = [0 for i in range(n)]
high = 0
for i in range(n):
    high = max(high, A[i])
    H[i] = high

mp = {}
for h in H:
    if h not in mp: mp[h] = 1
    else: mp[h] += 1
mx = max(mp.values())
ans = 1e9
for k, v in mp.items():
    if v == mx:
        ans = min(ans, k)

print(*H)
print(mp)
print(ans)