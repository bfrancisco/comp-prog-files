def gcd(a, b):
    if (a == 0):
        return b
    return (gcd(b % a, a))

x, y = map(int, input().split())
print(gcd(x, y))