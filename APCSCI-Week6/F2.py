import heapq as hq

def getValidPath(distances):
    revpath = []
    v = n
    while v != -1:
        revpath.append(v)
        v = distances[v][2]
    return revpath

def dijkstra(x):
    distances = [[-1, 1e13, -1] for i in range(n+1)]
    # sp number, weight, prev
    #prev = [[] for i in range(n+1)]
    distances[x] = [1, 0, -1]
    pq = [(-1, 0, x)]
    valid = []  # place here valid paths.
    while pq:
        mx_sp, curdist, v = hq.heappop(pq)
        # print(v, curdist)
        if -curdist > T:
            continue 
        # if -mx_sp > distances[v][0]:
        #     continue
        # if curdist > distances[v][1]:
        #     continue

        for next, weight in graph[v]:
            dist = (-curdist) + weight
            # print(v, next, dist)
            if dist > T or -mx_sp < distances[next][0]:
                continue
            # print('hapen')
            if distances[next][0] < (-mx_sp) + 1:
                distances[next] = [(-mx_sp) + 1, dist, v]
                hq.heappush(pq, (-((-mx_sp) + 1), -dist,  next))
            # elif distances[next][0] == (-mx_sp) + 1:
            #     if distances[next][1] < dist:
            #         distances[next] = [(-mx_sp) + 1, dist, v]

            if next == n:
                valid.append(getValidPath(distances))
    
    #print(*distances, sep = '\n')
    #print(valid, sep = '\n')
    optimal = []
    for path in valid:
        hq.heappush(optimal, (-len(path), path))
    
    print(-optimal[0][0])
    print(*reversed(optimal[0][1]))
    #return distances

n, m, T = map(int, input().split())
graph = [[] for i in range(n+1)]
for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

distances = dijkstra(1)



