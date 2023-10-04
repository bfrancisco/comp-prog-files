import heapq as hq

def dijkstra(x):
    distances = [[-1, 1e13, -1] for i in range(n+1)]
    # sp number, weight, prev
    #prev = [[] for i in range(n+1)]
    distances[x] = [1, 0, -1]
    pq = [(-1, 0, x)]

    while pq:
        mx_sp, curdist, v = hq.heappop(pq)
        #print(v)
        if -curdist > T:
            continue 
        # if -mx_sp > distances[v][0]:
        #     continue
        # if curdist > distances[v][1]:
        #     continue

        for next, weight in graph[v]:
            dist = (-curdist) + weight
            print(v, next, dist)
            if dist > T or -mx_sp < distances[next][0]:
                continue
            print('hapen')
            if distances[next][0] < (-mx_sp) + 1:
                distances[next] = [(-mx_sp) + 1, dist, v]
                hq.heappush(pq, (-((-mx_sp) + 1), -dist,  next))
            elif distances[next][0] == (-mx_sp) + 1:
                if distances[next][1] < dist:
                    distances[next] = [(-mx_sp) + 1, dist, v]
    
    #print(*distances, sep = '\n')
    revpath = []
    v = n
    showplaces = 0
    while v != -1:
        revpath.append(v)
        showplaces += 1
        v = distances[v][2]

    print(showplaces)
    print(*reversed(revpath))
    #return distances

n, m, T = map(int, input().split())
graph = [[] for i in range(n+1)]
for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

distances = dijkstra(1)



