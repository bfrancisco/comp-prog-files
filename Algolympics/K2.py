import sys

def g(x, a, n):
    return (x**2 + a) % n

n, a = map(int, input().split())
lim = 1000000
out = []
k = 0
for s in range(lim+1):
    if g(s, a, n) == s:
        k += 1
        out.append(s)

if k > lim:
    print("ABSOLUTELY WAY TOO MANY")
    exit()

print(k)
if k > 0:
    sys.stdout.write("\n".join(map(str,out)) + "\n")
