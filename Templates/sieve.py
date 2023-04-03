def sieve(n):
    # generates list of numbers from 1 to sqrt(n).
    # if 1, number is a prime. else, composite.
    sqr = n**(1/2) + 1
    prime = [1 for i in range(sqr+1)]
    p = 2
    while p*p <= sqr+1:
        if prime[p]:
            for i in range(p*p, sqr+1, p):
                prime[i] = 0
        p += 1