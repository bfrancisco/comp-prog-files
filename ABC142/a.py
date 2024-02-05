n = int(input())
a = [int(i) for i in input().split()]
ans = [0 for i in range(n)]

for i in range(n):
    ans[a[i]-1] = i+1

print(*ans)