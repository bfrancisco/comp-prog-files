n = int(input())
a = []
allh = 0
for i in range(n):
    x = input()
    sz = 0
    h = 0
    for c in x:
        if c == 'h':
            h += 1
        sz += 1
    allh += h
    a.append([h/sz, x])

a.sort()
ans = 0
#print(allh)
for score, x in a:
    for c in x:
        if c == 's':
            ans += allh
        else:
            allh -= 1
print(ans)
