from math import gcd, lcm

for a in range(1, 51):
    for b in range(1, 51):
        for n in range(1, 101):
            if gcd(a, b) + lcm(a, b) == n:
                print(a, b, n)
                break