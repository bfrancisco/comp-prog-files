from math import comb

def pfact(num):
    exps = []
    pushval = 0
    while num%2 == 0:
        pushval += 1
        num = num // 2
    exps.append(pushval)

    i = 3
    while (i*i <= num):
        pushval = 0
        while num%i == 0:
            pushval += 1
            num = num // i
        if pushval > 0:
            exps.append(pushval)
        i += 2
    
    if num > 2:
        exps.append(1)

    return exps

N, M = map(int, input().split())

exps = pfact(M)
ans = 1
mod = 1000000007
for e in exps:
    ans *= (comb(e+N-1, N-1) % mod)
print(ans % mod)
