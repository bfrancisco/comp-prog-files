def mod(x, m):
    if (m==0):
        return 0
    if (m < 0):
        m *= -1
    return (x%m + m) % m

def ext_euclid(a, b, x, y):
    if (b == 0):
        x = 1
        y = 0
        return a
    g = ext_euclid(b, a%b, x, y)
    z = x - a//b*y
    x = y
    y = z
    return g

def modinv(a, m):
    x = 0
    y = 0
    g = ext_euclid(a, m, x, y)
    if (g==1 or g == -1):
        return mod(x*g, m)
    return -1

for _ in range(int(input())):
    n,s,k = map(int, input().split())

    print(modinv(k, n-s))

