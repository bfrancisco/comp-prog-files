def pr(n, x):
    for i in range(n, n+x):
        print(i, end=' ', flush=True)

k = int(input())
p = 9
N = 2**p
print(N, flush=True)

n = N
for i in range(1, p+1):
    print(N//2)
    for i in range(1, N+1, n):
        pr(i, n//2)
    print(flush=True)
    input()
    print(N//2)
    for i in range(n//2+1, N+1, n):
        pr(i, n//2)
    print(flush=True)
    input()
    n = n//2

