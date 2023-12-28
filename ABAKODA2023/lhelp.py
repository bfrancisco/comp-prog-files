a = input()
vowels = set(list("AEIOUaeiou"))
cons = [c.upper() for c in a if c.isalpha() and c not in vowels]
n = len(cons) - 1
L = [' ']
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
for i in range(1, len(L)):
    print(L[i], '\t', i-1, '\t', bin(i)[2:])
# print(L[x-1] if x <= len(L) else "out of bounds")