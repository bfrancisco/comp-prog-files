import sys
from collections import deque

def bfs(start):
    q = deque([(start, 0, -1)])

    while q:
        v, x, prev = q.popleft()
        # print(v, x)
        if x in db:
            # print(x)
            for l, r in db[x]:
                if (l != start and r != start):
                    return True
        
        for next, weight in graph[v]:
            if next == prev:
                continue
            newx = x ^ weight
            q.append((next, newx, v))
    return False

for _ in range(int(input())):
    n, a, b = map(int, sys.stdin.readline().split())

    graph = [[] for i in range(n+1)]
    # s = set()
    db = {}
    for i in range(n-1):
        u, v, w = map(int, sys.stdin.readline().split())
        graph[u].append((v, w))
        graph[v].append((u, w))
        # s.add(w)
        if w not in db:
            db[w] = [sorted([u, v])]
        else:
            db[w].append(sorted([u, v]))
    # print(db)
    print("YES" if bfs(b) else "NO")

