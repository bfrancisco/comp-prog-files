from collections import deque

def getPath():
    revpath = []
    v = n
    while v != -1:
        revpath.append(v)
        v = dp[v][1]
    return list(reversed(revpath))

def bfs(start):
    optimal = []
    dp[start] = (0, -1)
    q = deque([start])

    while q:
        v = q.popleft()
        #print(v, dp[v])
        if v == n:
            optimal = getPath()
            #print(optimal)
            continue
        for next, weight in graph[v]:
            if dp[v][0] + weight > T:
                continue
            dp[next] = (dp[v][0] + weight, v)
            q.append(next)
    #print(dp)
    return optimal

n, m, T = map(int, input().split())
graph = [[] for i in range(n+1)]
for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

dp = [(float('inf'), -1) for _ in range(n+1)]
# [time,  prev]
bestPath = bfs(1)

print(len(bestPath))
print(*bestPath)