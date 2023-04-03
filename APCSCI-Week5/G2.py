from collections import deque

def bfs(v):
    q = deque([v])
    vis[v] = 1
    reg = [v]
    while q:
        vertex = q.popleft()
        for next in gr[vertex]:
            if not vis[next]:
                q.append(next)
                reg.append(next)
                vis[next] = 1
    return reg

n = int(input())
a = [int(i) for i in input().split()]

gr = [[] for i in range(n+1)]
for i in range(1, n+1):
    s = input()
    for j in range(1, n+1):
        if s[j-1] == '1':
            gr[i].append(j)

# for i in range(1, n+1):
#     print(i, gr[i])

regions = []
vis = [0 for i in range(n+1)]
for i in range(1, n+1):
    if vis[i]:
        continue
    regions.append(bfs(i))

for i in range(len(regions)):
    indeces = []
    vals = []
    for j in regions[i]:
        vals.append(a[j-1])
        indeces.append(j-1)
    indeces.sort()
    vals.sort()

    for k in range(len(indeces)):
        a[indeces[k]] = vals[k]


print(*a)