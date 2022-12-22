n = int(input())
a = [int(x) for x in input().split()]
precomp = (n*(n-1))//2
dct = {}
for x in a:
    if x in dct:
        dct[x] += 1
    else:
        dct[x] = 0
for x in a:
    precomp -= dct[x]
    dct[x] -= 1
print(precomp)