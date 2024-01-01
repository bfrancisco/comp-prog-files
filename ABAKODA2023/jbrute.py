# BRUTEFORCE
MX = 100000
prime = [True for i in range(MX+1)]
def sieve(num):
    p = 2
    while (p * p <= num):
        if (prime[p] == True):
            for i in range(p * p, num+1, p):
                prime[i] = False
        p += 1

sieve(MX)

def primefactorization(n):
    pf = []
    for p in range(2, int(n**(1/2))+1):
        if (not prime[p]): continue
        exp = 0
        x = n
        while(x % p == 0):
            exp += 1
            x /= p

        if (exp > 0):
            pf.append((p, exp))
    return pf

N, k = map(int, input().split())
ans = 0
for n in range(1, N+1):
    if (prime[n]):
        ans += 1
        continue
    pf = primefactorization(n)
    jolly = 1
    for p, e in pf:
        jolly = max(jolly, p**(e//k))
    ans += jolly
    # print(n, jolly)
print(ans)
