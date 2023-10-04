n = int(input())
D = []
ao = 0
for i in range(n):
    a, b = map(int, input().split())
    ao += a
    D.append(2*a + b)
    # taka += b
D.sort(reverse=True)
ta = 0
ans = 0
for v in D:
    ta += v
    ans += 1
    if ta > ao:
        break

print(ans)
