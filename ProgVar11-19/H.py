import sys
import heapq as hq

def dijkstra(start):
    distances = [float('inf') for i in range(n)]
    distances[start] = 0
    pq = [(0, start)]
    oddfix = 1
    while pq:
        if oddfix >= n:
            continue
        curdist, v = hq.heappop(pq)

        if curdist > distances[v]:
            continue

        distance = curdist + weight[v][oddfix]
        distances[oddfix] = distance

        for next in range(0, n, 2):
            if v == next:
                continue
            distance += weight[oddfix][next]
            if distance < distances[next]:
                distances[next] = distance
                hq.heappush(pq, (distance, next)) 
        oddfix += 2 
    #print(distances)
    if n%2 == 0:
        return distances[n-1]
    else:     
        mn = float('inf')
        for i in range(0, n, 2):
            if i == start:
                continue
            mn = min(mn, distances[i])
        return mn

n = int(sys.stdin.readline())
weight = [[int(i) for i in sys.stdin.readline().split()] for j in range(n)]

mn = float('inf')
for i in range(0, n, 2):
    mn = min(dijkstra(i), mn)
print(mn)