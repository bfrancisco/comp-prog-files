import sys
import heapq as hq

def dijkstra(start):
    distances = [float('inf') for i in range(n+1)]
    distances[start] = 0
    pq = [(0, start)]

    while pq:
        curdist, v = hq.heappop(pq)
        if curdist > distances[v]:
            continue

        for next, weight in adj_weight.items():
            distance = curdist + weight
            

n = int(sys.stdin.readline())
weight = []
weight.append([0]*(n+1))
for _ in range(n):
    temp = [0] + [int(i) for i in sys.stdin.readline().split()]
    weight.append(temp)

adj_weight = {i:{} for i in range(1, n+1, 2)}

for i in range(1, n+1, 2):
    even = 2
    for j in range(1, n+1, 2):
        if i == j:
            continue
        adj_weight[i][j] = weight[i][even] + weight[even][j]
        adj_weight[j][i] = weight[j][even] + weight[even][i]
        even += 2

for k, v in adj_weight.items():
    print(k, v)

# mn = float('inf')
# for start in range(1, n+1, 2):
#     mn = min(mn, dijkstra(start))

# include even vertices
