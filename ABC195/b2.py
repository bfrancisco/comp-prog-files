from math import lcm
a, b, k = map(int, input().split())
k *= 1000

if b < (k - (b*(k//b))):
    print("UNSATISFIABLE")
    exit()

print(((b*(k//b))))