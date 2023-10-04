n, m = map(int, input().split())
edges = []
for i in range(m):
    a, b, w = map(int, input().split())
    edges.append((a-1, b-1, -w))

mxscore = [float('inf')]*n
mxscore[0] = 0
for i in range(n-1):
    for u, v, w in edges:
        if mxscore[u] + w < mxscore[v]:
            mxscore[v] = mxscore[u] + w

ans = -mxscore[-1]
for i in range(n):
    for u, v, w in edges:
        if mxscore[u] + w < mxscore[v]:
            mxscore[v] = mxscore[u] + w

print(ans if ans == -mxscore[-1] else "inf")