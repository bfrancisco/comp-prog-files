mod = 1000000007

n, k = map(int, input().split())
K = k
a = [int(i) for i in input().split()]
pos,neg,zer = 0,0,0

for x in a:
    if x > 0:
        pos += 1
    elif x < 0:
        neg += 1
    else:
        zer += 1

a.sort()

if (pos + neg < k):
    print(0)
    exit()

l, r = 0, n-1
ans = 1
if (k%2):
    ans *= a[r]
    r-=1
    k-=1

while k:
    if (r-l == 1):
        ans *= a[l]
        ans %= mod
        ans *= a[r]
        ans %= mod
        break

    left, right = a[l]*a[l+1], a[r]*a[r-1]
    if left >= right:
        ans *= a[l]
        ans %= mod
        ans *= a[l+1]
        ans %= mod
        l += 2
    else:
        ans *= a[r]
        ans %= mod
        ans *= a[r-1]
        ans %= mod
        r -= 2
    k -= 2


negs = [x for x in a if x < 0]
negs.sort(reverse=True)
ans2 = 1
k2 = K
for i in range(k2):
    ans2 *= negs[i]
    ans2 %= mod

print(max(ans, ans2))