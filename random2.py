def rotate_90(l):
    return [list(reversed(x)) for x in zip(*l)]

def check_row(row):
    if len(set(row)) == 1:
        return True

def check_grid(grid):
    for row in grid:
        if check_row(row) and row[0] != '.':
            return row[0]
    return '.'

def solve():
    grid = [list(input()) for i in range(8)]

    letter = check_grid(grid)
    if letter not in ['R', 'S']:
        grid = rotate_90(grid)
        letter = check_grid(grid)
    
    print(letter)

def main():
    T = int(input())
    for i in range(T):
        input()
        solve()

main()