n, k = map(int, input().split())
a = [0]
while True:
    if a[-1]*k+1 > n:
        break
    a.append(a[-1]*k+1)

if len(a) > k+1:
    print(a[k] + (n-a[k+1]))
    exit()

ans = 0
while n > 0:
    ans += n // a[-1] * a[-2]
    n -= n // a[-1] * a[-1]

    while a[-1] > n:
        a.pop()

print(ans)