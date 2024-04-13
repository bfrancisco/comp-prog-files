from itertools import permutations
n, h = map(int, input().split())
a = []
for i in range(h):
    a.append(int(input()))
pref = [0 for i in range(h+1)]
for i in range(1, h+1):
    pref[i] = a[i-1] + pref[i-1]
ans = 0
# print(a)
# print(pref)
for p in permutations(range(1, n+1)):
    pas = 1
    for i in range(1, h+1):
        sub = list(p[n-pref[i]:])
        sub.sort()
        if sub == list(range(1, pref[i]+1)):
            pas = 0
            break
    ans += pas
    if (pas):
        print(p)

print(ans)