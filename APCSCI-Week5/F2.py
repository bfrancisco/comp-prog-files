import sys
sys.setrecursionlimit(10 ** 6)

def dfs(v, prev):
    print(v, end = " ")
    for next in gr[v]:
        if next != prev:
            dfs(next, v)
            print(v, end = " ")

n = int(input())
gr = [[] for i in range(n+1)]

for i in range(n-1):
    a, b = map(int, input().split())
    gr[a].append(b)
    gr[b].append(a)

for i in range(1, n+1):
    gr[i].sort()

dfs(1, -1)