import heapq as hq

def dijkstra(x):
    distances = [1e13 for i in range(n+1)]
    distances[x] = 0
    pq = [(0, x)]
    possible = [float('inf')]
    while pq:
        curdist, v = hq.heappop(pq)
        #print(v)
        if curdist > distances[v]:
            continue

        for next, weight in graph[v]:
            if next == start:
                hq.heappush(possible, curdist + weight)
                continue
            dist = curdist + weight
            if dist < distances[next]:
                distances[next] = dist
                hq.heappush(pq, (dist, next))
    
    return possible[0] if possible[0] != float('inf') else -1

n, m = map(int, input().split())
graph = [[] for i in range(n+1)]

for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

out = []

for start in range(1, n+1):
    out.append(dijkstra(start))

print(*out, sep = '\n')


