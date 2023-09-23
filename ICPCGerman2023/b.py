import sys
def SieveOfEratosthenes(num):
    prime = [True for i in range(num + 1)]
    p = 2
    while (p * p <= num):
        if (prime[p] == True):
            for i in range(p * p, num + 1, p):
                prime[i] = False
        p += 1
    return prime
is_prime = SieveOfEratosthenes(10**6)
n = int(input())
arr = [int(x) for x in sys.stdin.readline().split()]
temp = sorted(arr)
if temp[0] == 1 and temp[1] == 1:
    print(1)
    exit()
count = 1
d = {}
for x in arr:
    if x in d:
        pass
    else:
        d[x] = count
        count += 1
mx = 752
graph = [[0 for x in range(mx)] for y in range(mx)]
for x in range(n):
    for y in range(x+1,n):
        if is_prime[arr[x] + arr[y]]:
            graph[d[arr[x]]][d[arr[y]]] += 1
            graph[d[arr[y]]][d[arr[x]]] += 1
for x in arr:
    if x%2 == 0:
        graph[d[x]][mx-1] += 1
    else:
        graph[0][d[x]] += 1
def BFS(graph, s, t, parent):
    visited = [False] * len(graph)
    queue = []
    queue.append(s)
    visited[s] = True
    for u in queue:
        for ind in range(mx):
            if visited[ind] is False and graph[u][ind] > 0:
                queue.append(ind)
                visited[ind] = True
                parent[ind] = u
 
    return True if visited[t] else False
 
 
def FordFulkerson(graph, source, sink):
    parent = [-1] * (len(graph))
    max_flow = 0
    while BFS(graph, source, sink, parent):
        path_flow = float("Inf")
        s = sink
        while s != source:
            path_flow = min(path_flow, graph[parent[s]][s])
            s = parent[s]
 
        max_flow += path_flow
        v = sink
        while v != source:
            u = parent[v]
            graph[u][v] -= path_flow
            graph[v][u] += path_flow
            v = parent[v]
    return max_flow
print(n - FordFulkerson(graph, 0, mx-1))