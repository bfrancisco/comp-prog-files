n = int(input())

p, ne = 0, 0
for i in range(n):
    x, y = map(int, input().split())
    if x > 0:
        p += 1
    else:
        ne += 1

if p <= 1 or ne <= 1:
    print("Yes")
else:
    print("No")