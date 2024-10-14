n = int(input())
a = [int(i) for i in input().split()]

ans = [i for i in range(100, 100+n)]

prev_i = a.index(1)
target = 2
for target in range(2, n+1):
    for i in range(n):
        if target==a[i]:
            while ans[prev_i] > ans[i]:
                ans[i]*=10
            prev_i = i
            break
print(*ans)
