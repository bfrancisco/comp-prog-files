N = 100
vals = [0 for i in range(N+1)]
cumu = [0 for i in range(N+1)]
for n in range(1, N+1):
    c = 0
    for i in range(1, n+1):
        if n%i==0:
            c+=1
    
    vals[n] = n * c

for i in range(1, N+1):
    cumu[i] = cumu[i-1] + vals[i]

print(*cumu[1:])