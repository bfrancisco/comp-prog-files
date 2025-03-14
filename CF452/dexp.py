N = int(input())
K = 9
ans = 0
for i in range(1, N+1):
    for j in range(i+1, N+1):
        if (i+j)%(K+1) == K:
            ans += 1
print(ans)
