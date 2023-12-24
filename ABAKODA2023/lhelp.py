a = input()
vowels = set(list("AEIOUaeiou"))
cons = [c.upper() for c in a if c.isalpha() and c not in vowels]
n = len(cons) - 1
L = [" "]
x = int(input())
# 0 means adding space
for bit in range(1 << n):
    new = cons[0]
    for i in range(n):
        if not (bit & (1 << i)):
            new += ' '
        new += cons[i+1]
    L.append(new)

L.sort()
p2 = [1]

while (p2[-1] < (1<<n)):
    p2.append(p2[-1]*2)
print(p2)
for i in p2:
    print(i, ":", L[i])
print(L[8])
print(L[9])
print(L[10])
print(L[11])
print(L[12])

# print(L[x-1] if x <= len(L) else "out of bounds")