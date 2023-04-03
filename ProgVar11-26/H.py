import sys
# input = sys.stdin.readline()

n, k = map(int, sys.stdin.readline().split())
cs = []
db = {i:set() for i in range(1, k+1)}
for i in range(1,n+1):
    a, c = map(int, sys.stdin.readline().split())
    cs.append(c)
    db[c].add(a)

pas = True
num = 1
for c in cs:
    if num not in db[c]:
        pas = False
        break
    num += 1
print("Y" if pas else "N")