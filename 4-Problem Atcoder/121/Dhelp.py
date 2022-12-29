a, b = map(int, input().split())

x = 0
for e in range(a, b+1):
    x ^= e
print(x)

#print(bin(x))