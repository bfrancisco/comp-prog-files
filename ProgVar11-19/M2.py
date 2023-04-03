def ex():
    print('*')
    exit()

import sys
n = int(sys.stdin.readline())
a = []

for i in range(n):
    t, d = map(int, sys.stdin.readline().split())
    a.append((d, t, i+1))

a.sort()
prefixt = [a[0][1]]
for d, t, i in a[1:]:
    prefixt.append(prefixt[-1] + t)

lastdeadline = a[0][0]
tosort = [a[0][2]]
out = []
for i in range(1, n):
    if prefixt[i] > a[i][0]:
        ex()
    
    if prefixt[i] <= lastdeadline:
        tosort.append(a[i][2])
    else:
        tosort.sort()
        for j in tosort:
            out.append(j)
        tosort = [a[i][2]]
        lastdeadline = a[i][0]

if tosort: 
    tosort.sort()
    for j in tosort:
        out.append(j)

print(*out)