D = {
    "N" : (-1, 0),
    "E" : (0, 1),
    "W" : (0, -1),
    "S" : (1, 0),
}

from itertools import permutations

R, C = map(int, input().split())
grid = [list(input()) for i in range(R)]
sr, sc, er, ec = 0,0,0,0
for r in range(R):
    for c in range(C):
        if grid[r][c] == 'S':
            sr, sc = r, c
        elif grid[r][c] == 'E':
            er, ec = r, c


dirs = [int(i) for i in input()]

# print(sr, sc, er, ec)

def do(p):
    r, c = sr, sc
    for i in dirs:
        r += D[p[i]][0]
        c += D[p[i]][1]
        if not (0 <= r and r < R and 0 <= c and c < C) or grid[r][c] == '#':
            return 0
        if r == er and c == ec:
            return 1
    return 0  


ans = 0
for p in permutations("NEWS"):
    # print(p)
    ans += do(p)

print(ans)

