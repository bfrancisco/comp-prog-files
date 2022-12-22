from itertools import permutations

a = [
    'hssss',
    'hssssh',
    'ssssh',
    'hhssss',
    'hssssss',
    'sh',
    'ssss',
    'hhh'
]

best = ''
ms = -1
pe = []
for p in permutations([0,1,2,3,4,5,6,7]):
    s = ''
    for i in p:
        s += a[i]
    score = 0
    h = s.count('h')
    for c in s:
        if c == 's':
            score += h
        else:
            h -= 1
    if score > ms:
        ms = score
        pe = p
        best = s
    if score == 224:
        print(s, p)
print(best, ":", ms)
print(pe)