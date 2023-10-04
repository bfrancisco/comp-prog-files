from collections import deque
def valid(r, c):
    if 0 <= r < h and 0 <= c < w:
        return True
    return False 

def bfs(r, c, r2, c2):
    q = deque([[r, c, 0]])
    score = -1
    vis = set()
    vis.add((r, c))
    while q:
        x, y, score = q.popleft()
        
        if x == r2 and y == c2:
            break
        for addx, addy in dirs:
            newX = x + addx
            newY = y + addy
            if valid(newX, newY) and grid[newX][newY] != '#' and (newX, newY) not in vis:
                q.append([newX, newY, score+1])
                vis.add((newX, newY))
    return score

def bfs2(r, c):
    q = deque([[r, c, 0]])
    score = -1
    vis = set()
    vis.add((r, c))
    endx, endy = -1, -1
    dis = -1
    while q:
        x, y, score = q.popleft()
        endx, endy = x, y
        #print(x, y)
        for addx, addy in dirs:
            newX = x + addx
            newY = y + addy
            if valid(newX, newY) and grid[newX][newY] == '.' and (newX, newY) not in vis:
                q.append([newX, newY, score+1])
                vis.add((newX, newY))
    return score, endx, endy

h, w = map(int, input().split())
grid = [list(input()) for i in range(h)]
dirs = [(0, -1), (0, 1), (-1, 0), (1, 0)]
# find farthest pair
dis = -1
start = [-1, -1]
end = [-1, -1]
for r in range(h):
    for c in range(w):
        if grid[r][c] == '#':
            continue
        #print(r, c)
        score, x, y = bfs2(r, c)
        if score > dis:
            dis = score
            start[0], start[1] = r, c
            end[0], end[1] = x, y
        
# find shortest path
#print(start)
#print(end)
# ....................

print(bfs(start[0], start[1], end[0], end[1]))