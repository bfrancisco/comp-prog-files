from collections import deque

def valid(x, y):
    if 0 <= x < n and 0 <= y < m:
        return True
    return False

def bfs(x, y, c):
    q = deque([[x, y, (-1,-1)]])
    vis = set()
    vis.add((x, y))

    while q:
        X, Y, prev = q.popleft()
        for i, j in dirs:
            if valid(X+i, Y+j) and grid[X+i][Y+j] == c and (X+i, Y+j) not in vis:
                q.append([X+i, Y+j, (X,Y)])
                vis.add((X+i, Y+j))
            elif (X+i, Y+j) in vis and (X+i, Y+j) != prev and prev != (-1, -1):
                return True
    return False


n, m = map(int, input().split())

grid = [list(input()) for i in range(n)]
dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
pas = False
for i in range(n):
    for j in range(m):
        if bfs(i, j, grid[i][j]):
            #print(i, j)
            pas = True
            break
    if pas:
        break

print("Yes" if pas else "No")
