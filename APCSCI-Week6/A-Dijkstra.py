import heapq as hq

def dijkstra(x, prev):
    distances = [1e13 for i in range(n+1)]
    distances[x] = 0
    pq = [(0, x)]

    while pq:
        curdist, v = hq.heappop(pq)
        #print(v)
        if curdist > distances[v]:
            continue

        for next in graph[v]:
            edge = tuple(sorted([v, next]))
            dist = curdist + weight[edge]

            if dist < distances[next]:
                distances[next] = dist
                prev[next] = v
                hq.heappush(pq, (dist, next))
    
    #return distances

n, m = map(int, input().split())
graph = [[] for i in range(n+1)]
weight = {}
for i in range(m):
    a, b, w = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    ab = tuple(sorted([a, b]))
    weight[ab] = w

#print(graph)
prev = [-1 for i in range(n+1)]
dijkstra(1, prev)

revpath = []
v = n
while v != -1:
    revpath.append(v)
    v = prev[v]

#print(prev[1:])
if revpath[-1] != 1:
    print(-1)
else:
    print(*reversed(revpath))