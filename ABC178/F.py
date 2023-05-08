from collections import deque

n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
d = deque(b)
freq = {}
for x in a:
    if x not in freq:
        freq[x] = 1
    else:
        freq[x] += 1

for x in b:
    if x not in freq:
        freq[x] = 1
    else:
        freq[x] += 1

pas = True
for k, v in freq.items():
    if v > n:
        pas = False
        break
if not pas:
    print("No")
    exit()

for i in range(n):
    j = i
    while a[j] == d[j]:
        d.rotate()
        # print(d)
        j = (j+1)%n

print("Yes")
print(*d)