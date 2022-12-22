import heapq as hq

def getValidPath(time_prev):
    revpath = []
    v = n
    while v != -1:
        revpath.append(v)
        v = time_prev[v][1]
        #time_prev[v] = [float('inf'), -1]
    return list(reversed(revpath))


def dfs(start):
    validPaths = []
    #visited = [0 for _ in range(n+1)]
    time_prev = [[float('inf'), -1] for _ in range(n+1)]
    time_prev[1] = [0, -1]
    stack = [(start, 0)] # vertex, time

    while stack:
        v, time = stack.pop()
        if time > T:
            continue

        if v == n:
            # for i in range(1, n+1):
            #     print(i, time_prev[i]) 
            validPaths.append(getValidPath(time_prev))
            #visited = [0 for _ in range(n+1)]
            continue

        #visited[v] = 1
        for next, weight in graph[v]:
            # if visited[next]:
            #     continue
            time_prev[next] = [time + weight, v]
            stack.append((next, time + weight))

    #print(validPaths)
    optimal = []
    for path in validPaths:
        hq.heappush(optimal, (-len(path), path))

    print(-optimal[0][0])
    print(*optimal[0][1])


n, m, T = map(int, input().split())
graph = [[] for i in range(n+1)]
for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

validPaths = dfs(1)