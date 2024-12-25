for _ in range(int(input())):
    n = int(input())
    a = [0] + [int(i) for i in input().split()] + [0]
    n += 2
    if sum(a) == 0:
        print(0)
        continue
    
    inds = []
    for i in range(n):
        if a[i] == 0:
            inds.append(i)
    
    