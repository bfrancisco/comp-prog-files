from itertools import permutations

n=int(input())

for p in permutations([i for i in range(1, n+1)]):
    sm = 0
    s = set()
    pas = True
    for x in p:
        sm += x
        if (sm%n) in s:
            pas = False
            break
        s.add(sm%n)

    if pas:
        print(*p, end='        ')
        print()
        # z = 0
        # zz = []
        # for v in p:
        #     z += v
        #     zz.append(z)
        #     print(z%n, end=' ')
        # print("        ", end='')
        # print(*zz)
