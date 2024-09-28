def mod(val):
    return val%37

def multiply(A, B):
    p = len(A)
    q = len(A[0])
    r = len(B[0])
    AB = [[0 for j in range(r)] for i in range(p)]
    for i in range(p):
        for j in range(q):
            for k in range(r):
                AB[i][k] += mod(A[i][j] * B[j][k])
                AB[i][k] = mod(AB[i][k])
    return AB

abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "
n = int(input())
m = [[int(i) for i in input().split()] for j in range(n)]
s = input()

while len(s)%n != 0:
    s += " "

grp = []
for i in range(0, len(s), n):
    v = []
    for j in range(i, i+n):
        v.append(abc.index(s[j]))
    
    grp.append(v)
# print(grp)
# print(*m, sep='\n')

new = []
for row in grp:
    tomul = [[e] for e in row]
    new.append(multiply(m, tomul))

for mat in new:
    for row in mat:
        for e in row:
            print(abc[e], end='')
print()