def g(x, a, n):
    return (x**2 + a) % n

n = 103
a = 10

for i in range(1, n+1):
    print(i, g(i, a, n))
