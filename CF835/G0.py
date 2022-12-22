import sys
from collections import deque
 
def bfs(start):
    q = deque([(start, 0, -1)])
 
    while q:
        v, x, prev = q.popleft()
        if x in s:
            #print(x)
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
    s = set()
    for i in range(n-1):
        u, v, w = map(int, sys.stdin.readline().split())
        graph[u].append((v, w))
        graph[v].append((u, w))
        if u != b and v != b:
            s.add(w)
    print("YES" if bfs(b) else "NO")