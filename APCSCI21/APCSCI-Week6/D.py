import heapq as hq

def dijkstra(x, y):
    distances = [float('inf') for i in range(n+1)]
    distances[x] = 0
    pq = [(0, x)]

    while pq:
        curdist, v = hq.heappop(pq)
        #print(v)
        if curdist > distances[v]:
            continue
        #print(v, curdist)
        for next, time, interv in graph[v]:
            if curdist % interv == 0:
                tempdist = curdist + time
            else:
                tempdist = curdist + (interv - (curdist % interv)) + time

            if tempdist < distances[next]:
                distances[next] = tempdist
                hq.heappush(pq, (tempdist, next))
        #print(v, curdist)
    return distances

n, m, x, y = map(int, input().split())

graph = [[] for i in range(n+1)]
for i in range(m):
    u, v, t, k = map(int, input().split())
    graph[u].append((v, t, k))
    graph[v].append((u, t, k))

# for i in range(1, n+1):
#     print(i, graph[i])

dist = dijkstra(x, y)
#print(dist)
print(-1 if dist[y] == float('inf') else dist[y])
