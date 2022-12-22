# represent 3x3 grid in code
# 2D List
grid = [
    [1, 2, 3], # grid 0
    [4, 5, 6],
    [7, 8, 9]
]


# GETTING ELEMENTS IN A 2D LIST
# get first row in grid
#print(grid[0])
#print(grid[2])

# get specific cell in grid
#print(grid[0][1])


# UPDATING CELLS IN 2D LIST
grid[0][2] = 9
grid[2][1] = 1

for row in grid:
    print(*row)