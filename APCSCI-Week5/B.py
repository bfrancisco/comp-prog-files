from sys import setrecursionlimit
setrecursionlimit(2001)

def dfs(start):
    global ans
    ans += 1
    vis[start] = 1
    for e in graph[start]:
        #print(e)
        if not vis[e]:
            dfs(e)

n, m = map(int, input().split())
graph = [[] for i in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

ans = 0
for start in range(1, n+1):
    vis = [0 for i in range(n+1)]
    dfs(start)

print(ans)