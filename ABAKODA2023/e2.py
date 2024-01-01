def pr(n, x):
    for i in range(n, n+x):
        print(i, end=' ', flush=True)

k = int(input())
p = 3
N = 2**p
print(N, flush=True)
n = N
print(N//2)
for x in range(2, N+1, 2):
    print(x, end=" ", flush=True)
print(flush=True)
for i in range(2, p+2):
    print(N//i)
    for x in range(1, N+1, i):
        print(x, end=" ", flush=True)
    print(flush=True)




