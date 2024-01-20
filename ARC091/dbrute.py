n, k = map(int, input().split())
ans = 0
# s = []
for a in range(1, n+1):
    for b in range(1,n+1):
        if (a%b) >= k:
            ans+=1
            # s.append((a,b))

print(ans)
# print(len(s))