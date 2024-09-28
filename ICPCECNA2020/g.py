n, m = map(int, input().split())
rank = [i for i in range(n)]

for _ in range(m):
    p, q = input().split()
    i, j = int(p[1:]), int(q[1:])
    i -= 1
    j -= 1
    if rank[i] > rank[j]:
        rj = rank[j]
        rank[j] = rank[i]
        for k in range(n):
            if rj < rank[k] and rank[k] <= rank[i] and k != j:
                rank[k] -= 1
        
ans = ["" for i in range(n)]
# print(*rank)
for i in range(n):
    ans[rank[i]] = f"T{i+1}"

print(*ans)