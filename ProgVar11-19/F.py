import sys

def bfs(start, out):
    out[start] = 'B'
    q = [start]
    for v in q:
        for next in graph[v]:
            if out[next] == '':
                out[next] = 'B'
                q.append(next)

n, m = map(int, sys.stdin.readline().split())

graph = [[] for i in range(n+1)]
for i in range(m):
    v, u = map(int, sys.stdin.readline().split())
    graph[v].append(u)
    graph[u].append(v)

out = ['' for i in range(n+1)]
out[n] = 'A'
bfs(n-1, out)

for i in range(1, n+1):
    if out[i] == 'B':
        print("B", end='')
    else:
        print("A", end='')