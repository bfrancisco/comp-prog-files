for _ in range(int(input())):
    n, m = map(int, input().split())
    nodes = [i for i in input().split()]
    mp = {nodes[i]:i for i in range(n)}
    adj = [[] for i in range(n)]
    for _ in range(m):
        u, v = [i for i in input().split()]
        adj[mp[u]].append(mp[v])
        adj[mp[v]].append(mp[u])
    
    tym = 0
    cycles = 0
    start = [-1 for i in range(n)]
    for i in range(n):
        if (start[i] != -1):
            continue
        stack = [(i, -1)]
        while (stack):
            u, p = stack.pop()
            if (start[u] != -1):
                continue
            # print(u, nodes[u], p, nodes[p])
            start[u] = tym
            tym += 1
            for v in adj[u]:
                if (v == p):
                    continue
                if (start[v] == -1):
                    stack.append((v, u))
                elif (v != p and start[v] < start[u]):
                        cycles += 1
                        # print(u, v)
                        
                    
    
    # print(cycles)
    # print(start)
    edg = [0 for i in range(n)]
    for i in range(n):
        edg[len(adj[i])] += 1
    
    if (n >= 5 and edg[3] == 2 and edg[1] == 2 and (edg[1]+edg[2]+edg[3]) == n and cycles == 1 and n==m):
        print("Alice")
    elif (n >= 5 and edg[4] == 1 and edg[2]+edg[4] == n and cycles == 2 and n == m-1):
        print("Bob")
    elif (n >= 5 and edg[1] == 2 and edg[1]+edg[2] == n and cycles == 0 and n-1 == m):
        print("Cindy")
    else:
        print("PRANKED")