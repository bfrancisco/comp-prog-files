import sys
input = sys.stdin.readline

def topo(graph, rev):
    indeg = [len(rev[i]) for i in range(len(rev))]
    q = []
    for i in range(len(indeg)):
        if indeg[i] == 0:
            q.append(i)
    ret = []
    for v in q:
        ret.append(v)
        for next in graph[v]:
            indeg[next[0]] -= 1
            if indeg[next[0]] == 0:
                q.append(next[0])
    return ret

def out(i, dp, rev, n):
    v, ind = n-1, i
    ans = [n-1]
    while v:
        nx, mn = -1, float('inf')
        for next in rev[v]:
            if w + dp[next[0]][ind-1] < mn:
                mn = next[1] + dp[next[0]][ind-1]
                nx = next[0]
        ans.append(nx)
        v = nx
        ind -= 1
    print(len(ans))
    for i in range(len(ans)-1, -1, -1):
        print(ans[i]+1, end=' ')
    
n, m, T = map(int, input().split())
graph = [[] for i in range(n)]
rev = [[] for i in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    graph[u].append((v, w))
    rev[v].append((u, w))

tops = topo(graph, rev)
# print(tops)
dp = [[float('inf') for i in range(n)] for j in range(n)]
dp[0][0] = 0
for i in range(1, n):
    for v in tops:
        for prev in rev[v]:
            dp[v][i] = min(dp[v][i], prev[1] + dp[prev[0]][i-1])

for i in range(n-1, -1, -1):
    if dp[n-1][i] <= T:
        out(i, dp, rev, n)
        exit()
