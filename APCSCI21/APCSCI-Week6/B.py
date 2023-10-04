from collections import deque 

def bfs(start, vis):
    buy, sell = gold[start], 0
    q = deque([(start, buy, sell)])
    optimal = -1e11
    while q:
        v, l, r = q.popleft()
        optimal = max(r - l, optimal)
        vis[v] = 1
        if r == 0:
            for next in graph[v]:
                if not vis[next]:
                    q.append((next, l, gold[next]))
        else:
            mn = min(l, r)
            for next in graph[v]:
                if not vis[next]:
                    q.append((next, mn, max(r, gold[next])))

    return optimal

n, m = map(int, input().split())
gold = [0] + [int(i) for i in input().split()]
graph = [[] for i in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

vis = [0 for i in range(n+1)]
ans = -1e11
for i in range(1, n+1):
    if graph[i] and not vis[i]:
        ans = max(ans, bfs(i, vis))

print(ans)
