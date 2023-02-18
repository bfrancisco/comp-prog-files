def highp(n, p):
    x = 0
    while n:
        n /= p
        x += n
    return x

def zeroc(x):
    c = 0
    i = 5
    while n/i >= 1:
        c += n//i
        i*=5
    return c

for _ in range(int(input())):
    n, m = map(int, input().split())

    print(zeroc(n))
    print(highp(10*zeroc(n), m))
