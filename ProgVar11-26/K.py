import sys
T, D, M = map(int, sys.stdin.readline().split())

prev = 0
pas = False
for i in range(M):
    y = int(sys.stdin.readline())
    if y - prev >= T:
        pas = True
    prev = y
if D - prev >= T:
    pas = True

print("Y" if pas else "N")