N = 20
a = [0 for i in range(N+1)]
orig = [0 for i in range(N+1)]
for n in range(1, N+1):
    c = 0
    for i in range(1, n+1):
        if n%i==0:
            c += 1
    a[n] = c*n
    orig[n] = c

pref = [a[0]]
for i in range(1, N+1):
    pref.append(pref[-1] + a[i])

print(*orig)
print(*pref)