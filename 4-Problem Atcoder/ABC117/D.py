a = [int(i) for i in input().split()]

x = 0
for e in a:
    x ^= e

print(x)
