h, w = map(int, input().split())
grid = [[0 for i in range(w)] for j in range(h)]

a = [int(i) for i in input().split()]
for i in range(w):
    if a[i] > h:
        print("impossible")
        exit()
    for j in range(a[i]):
        grid[i][j] = 1
