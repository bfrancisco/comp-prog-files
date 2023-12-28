a = input()
vowels = set(list("AEIOUaeiou"))
cons = [c.upper() for c in a if c.isalpha() and c not in vowels]
n = len(cons) - 1
x = int(input())
# 0 means adding space
if (x > 2**n):
    print("out of bounds")
    exit()
b = bin(x-1)[2:].rjust(n, '0')
ans = [cons[0]]
for i in range(n):
    if (b[i] == '0'):
        ans.append(" ")
    ans.append(cons[i+1])
print(*ans, sep='')

