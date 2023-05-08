from collections import deque

n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
d = deque(b)

print(d)
print(d[0])
d.rotate()
print(d[0])