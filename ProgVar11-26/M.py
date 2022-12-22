q = int(input())
alive = [True for x in range(10**5 + 1)]
child = [[] for x in range(10**5 + 1)]
count = 2
monarch = 1
for x in range(q):
    a,b = [int(x) for x in input().split()]
    if a == 1:
        child[b].append(count)
        count += 1
    if a == 2:
        alive[b] = False
         


