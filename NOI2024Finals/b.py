N = int(input())
value = [int(i) for i in input().split()]

ns = []
z = N
while z > 1:
    ns.append(z)
    z = z - z//2
ns.append(1)
ns.reverse()
p_contrib = [1]
for i in range(1, len(ns)):
    contrib = [0 for k in range(ns[i])]
    for j in range(ns[i-1]):
        contrib[j] += p_contrib[j] * (ns[i-1]-j)
        contrib[-j-1] += p_contrib[j] * (ns[i-1]-j)
    p_contrib = contrib

num = 0
den = 0
for i in range(N):
    num += p_contrib[i]*value[i]
    den += p_contrib[i]

print(f'{(num/den):.12f}')