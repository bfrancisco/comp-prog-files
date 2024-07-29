mp = {
    '0' : 0,
    '1' : 1,
    '2' : 2,
    '3' : 3,
    '4' : 4,
    '5' : 5,
    '6' : 6,
    '7' : 7,
    '8' : 8,
    '9' : 9,
    'a' : 10,
    'b' : 11,
    'c' : 12,
    'd' : 13,
    'e' : 14,
    'f' : 15,
}

def hextodec(s):
    val = 0
    mul = 0
    for c in reversed(s):
        val += mp[c] * 16**mul
        mul += 1
    return val

n, m, k = map(int, input().split())
b = []
a = []
for i in range(n):
    b.append(hextodec(input()))
for i in range(m):
    a.append(hextodec(input()))

# print(*b)
# print(*a)

prefb = [b[0]]
for i in range(1, n):
    prefb.append(prefb[-1] ^ b[i])

# print(*prefb)


db = {}
for i in range(n):
    if prefb[i] not in db:
        db[prefb[i]] = i

for i in range(m):
    if a[i] in db:
        print(db[a[i]] + 1)
    else:
        print(-1)   
