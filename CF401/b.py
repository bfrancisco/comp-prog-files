n = int(input())
a = [int(i) for i in input()]
b = [int(i) for i in input()]

f1 = [0 for i in range(10)]
f2 = [0 for i in range(10)]

for e in b:
    f1[e] += 1
for e in b:
    f2[e] += 1

ansa, ansb = 0, 0
for e in a:
    flick = True
    for i in range(e, 10):
        if f1[i] >= 1:
            f1[i] -= 1
            flick = False
            break
    
    if flick:
        for i in range(10):
            if f1[i] >= 1:
                f1[i] -= 1
                break
        ansa += 1

for e in a:
    flick = False
    for i in range(e+1, 10):
        if f2[i] >= 1:
            flick = True
            ansb += 1
            f2[i] -= 1
            break
    
    if not flick:
        for i in range(10):
            if f2[i] >= 1:
                f2[i] -= 1
                break

print(ansa, ansb, sep='\n')
