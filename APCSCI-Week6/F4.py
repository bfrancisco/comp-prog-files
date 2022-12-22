from collections import deque

def getPath():
    revpath = []
    v = n
    while v != -1:
        revpath.append(v)
        v = dp[v][2]
    return list(reversed(revpath))

def bfs(start):
    optimal = []
    dp[start] = (0, 1, -1)
    q = deque([start])

    while q:
        v = q.popleft()
        if v == n and dp[n][0] <= T:
            optimal = getPath()
            continue
        for next, weight in graph[v]:
            if dp[v][0] + weight > T:
                continue
            if dp[next][1] < dp[v][1] + 1:
                dp[next] = (dp[v][0] + weight, dp[v][1] + 1, v)
                q.append(next)
            elif dp[next][1] == dp[v][1] + 1 and dp[next][0] > dp[v][0] + weight:
                dp[next] = (dp[v][0] + weight, dp[v][1] + 1, v)
                q.append(next)
    #print(dp)
    return optimal

n, m, T = map(int, input().split())
graph = [[] for i in range(n+1)]
for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

dp = [(float('inf'), -1, -1) for _ in range(n+1)]
# [time, no. of vertex, prev]
bestPath = bfs(1)

print(len(bestPath))
print(*bestPath)