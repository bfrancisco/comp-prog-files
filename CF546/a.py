n = int(input())
v = []
for i in range(n):
    a, b = map(int, input().split())
    v.append((a, b))
x = int(input())

ans = n
for l, r in v:
    if l <= x and x <= r:
        break
    ans -= 1

print(ans)