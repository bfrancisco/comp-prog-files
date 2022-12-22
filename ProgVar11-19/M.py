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
#print(a)
out = []
tosort = [a[0][2]]
last = a[0][0]
time = a[0][1]
for i in range(1, n):
    time += a[i][1]
    if time > a[i][0]:
        ex()
    if time > last:
        last = a[i][0]
        tosort.sort()
        for j in tosort:
            out.append(j)
        tosort = [a[i][2]]
    else:
        tosort.append(a[i][2])

tosort.sort()
for j in tosort:
    out.append(j)

print(*out)

