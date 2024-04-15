from math import gcd

def affine(a, x, b):
    c = ((a*(ord(x) - ord('a')) + b) + 26) % 26

    return chr(c+ord('a'))

As = []
for i in range(1, 26):
    if gcd(i, 26) == 1:
        As.append(i)

# print(As)

n = int(input())
words = [i for i in input().split()]
key = input()

good = set()
for word in words:
    for a in As:
        for b in range(0, 26):
            tmp = ""
            for c in word:
                tmp += affine(a, c, b)
            if key == tmp:
                good.add((a, b))        

# print(good)
sans = set()
for word in words:
    for a, b in good:
        tmp = ""
        for c in word:
            tmp += affine(a, c, b)
        sans.add(tmp)

ans = []
for x in sans:
    ans.append(x)
ans.sort()
print(*ans)