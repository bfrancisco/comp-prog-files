# 1118 1680
# 4072324

n = int(input())

X = {}
done = set()
coors = []
for i in range(n):
    x, y = map(int, input().split())
    if (x not in X):
        X[x] = {y : i}
    else:
        X[x][y] = i

    coors.append((x, y))

z = [
    [1118, 1680],
    [1118, -1680],
    [-1118, 1680],
    [-1118, -1680],
    [1680, 1118],
    [1680, -1118],
    [-1680, 1118],
    [-1680, -1118],
    [2018, 0],
    [-2018, 0],
    [0, 2018],
    [0, -2018],
]

ans = 0
for i in range(n):
    
    x, y = coors[i]
    # print("curr: ", x, y)
    for ax, ay in z:
        nx, ny = x+ax, y+ay
        if (nx in X and ny in X[nx] and X[nx][ny] not in done):
            ans += 1
    
    done.add(i)
    
    # print(done)

print(ans)
    

