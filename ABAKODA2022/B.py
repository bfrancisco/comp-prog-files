def print_pattern(a,b,c,move):
    for x,y,z in moveset[move]:
        out = ['.' for i in range(9)]
        out[y] = b
        out[x] = a
        out[z] = c
        print(*out, sep='')

n = int(input())
secondi = input()
letters = list(input())

# 1 - right over m. 0 - left over m
move = 1 if secondi[0] == 'r' else 0
moveset = [
    [[0, 4, 8], [1, 3, 8], [2, 2, 8], [3, 1, 8]],
    [[0, 4, 8], [0, 5, 7], [0, 6, 6], [0, 7, 5]]
    ]

for i in range(n):
    print_pattern(letters[0], letters[1], letters[2], move)
    if move == 0:
        letters[0], letters[1] = letters[1], letters[0]
    elif move == 1:
        letters[1], letters[2] = letters[2], letters[1]
    move = 1 - move

out = ['.' for i in range(9)]
out[0] = letters[0]
out[4] = letters[1]
out[8] = letters[2]
print(*out, sep='')