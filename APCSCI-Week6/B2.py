n, m = map(int, input().split())
gold = [0] + [int(i) for i in input().split()]
graph = [[] for i in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

vis = [0 for i in range(n+1)]
mini = [1e11 for i in range(n+1)]

for v in range(1, n+1):
    if graph[v]:
        for next in graph[v]:
            mini[next] = min([gold[v], mini[v], mini[next]])

#print(mini)
ans = -1e11
for v in range(1, n+1):
    ans = max(ans, gold[v] - mini[v])
print(ans)