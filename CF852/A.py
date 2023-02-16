for _ in range(int(input())):
    a, b = map(int, input().split())
    n, m = map(int, input().split())

    v = []
    # ratio : cost : minus  
    v.append([a*m / min((m+1), n), min(m+1, n), a*m])
    v.append([a / 1, 1, a])
    v.append([b / 1, 1, b])

    v.sort()
    n = n // v[0][]
    
