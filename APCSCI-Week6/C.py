n, m = map(int, input().split())
edges = []
weight = {}
for i in range(m):
    a, b, w = map(int, input().split())
    ab = (a, b)
    edges.append(ab)
    weight[ab] = w

mxscore = [-float('inf') for i in range(n+1)]
mxscore[1] = 0
for i in range(n-1):
    for u, v in edges:
        if mxscore[u] != -float('inf') and mxscore[u] + weight[(u, v)] > mxscore[v]:
            mxscore[v] = mxscore[u] + weight[(u, v)]

for u, v in edges:
    if mxscore[u] != -float('inf') and mxscore[u] + weight[(u, v)] > mxscore[v]:
        print("inf")
        exit()

print(mxscore[n])