from itertools import permutations

for n in range(3, 11):
    c = 0
    for p in permutations(range(1, n+1)):
        if p[-1] == 1:
            c += 1
    
    print(n, c)
