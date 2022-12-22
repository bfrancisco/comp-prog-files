import sys
import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n = int(input())
gr = [[] for i in range(n+1)]

for i in range(n-1):
    a, b = map(int, input().split())
    gr[a].append(b)
    gr[b].append(a)

for i in range(1, n+1):
    gr[i].sort(reverse=True)

vis = [0 for i in range(n+1)]
prev = [-1 for i in range(n+1)]
stack = [1]
while stack:
    v = stack.pop()
    # print(v, end=' ')
    sys.stdout.write(str(v) + ' ')
    if vis[v] and v != 1:
        stack.append(prev[v])
    vis[v] = 1
    noneigh = True
    for neigh in gr[v]:
        if not vis[neigh]:
            noneigh = False
            stack.append(neigh)
            prev[neigh] = v
    if noneigh:
        if v == 1:
            break
        else:
            stack.append(prev[v])

