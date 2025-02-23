for _ in range(int(input())):
    w, f = map(int, input().split())
    n = int(input())
    a = [int(i) for i in input().split()]
    a.sort(reverse=True)

    t = 0
    ew, ef = 0, 0
    
    for x in a:
        if ew > x or ef > x:
            