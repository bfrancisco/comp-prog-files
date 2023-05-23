n, m = map(int, input().split())
a = [int(i) for i in input().split()]

ps = [0]
for i in range(n):
    ps.append(ps[-1] + a[i])

# print(*ps)

# 0  1 2 3 4 5  6 7  8 9  10 11 12
# 29 7 5 7 9 51 7 13 8 55 42 9  81

mods = [a[i]%m for i in range(n)]
print(*mods)


for i in range(n):
    for j in range(i, n):
        if sum(a[i:j+1]) % m == 0:
            print(i, j)
            # print(a[i], a[j])