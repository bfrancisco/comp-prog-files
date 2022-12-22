n = int(input())
a = []
for i in range(n):
    x = input()
    s, h = 0, 0
    for c in x:
        if c == 's':
            s += 1
        else:
            h += 1
    a.append([s-h, -s, x])

a.sort(reverse=True)
b = []

for sc, ss, st in a:
    b.append(st)
word = ''.join(b)
print(a)
allh = word.count('h')

score = 0
for c in word:
    if c == 's':
        score += allh
    else:
        allh -= 1
print(score)