def f(S):
    left = ""
    for i in range(len(S)):
        if S[i] == '.':
            continue
        if S[i] == 'e':
            break
        left += S[i]
    
    left = int(left) 

    right = ""
    for i in range(len(S)-1, -1, -1):
        if S[i] == 'e':
            break
        right += S[i]
    
    right = int(right[::-1])

    return left, right-9

def comp(x, ex, y, ey):
    if x == 0:
        return "Incorrect"

    if ex <= ey:
        while ex < ey:
            ey -= 1
            y *= 10
    else:
        while ex > ey:
            ex -= 1
            x *= 10

    abso = abs(x-y)
    rela = abso/y

    # print("R:", rela, "A:", abso)
    # print(x, ex)
    # print(y, ey)

    if rela < 1 and abso < 1:
        return "Correct"

    return "Incorrect"
    

A, B, P, S, M, D = [input() for _ in range(6)]
a, ea = f(A)
b, eb = f(B)
stud = [f(x) for x in [P,S,M,D]]

if ea <= eb:
    while ea < eb:
        eb -= 1
        b *= 10
else:
    while ea > eb:
        ea -= 1
        a *= 10

add = a+b
eadd = ea

sub = a-b
esub = ea

mul = a*b 
emul = ea+eb

div = a/b
ediv = ea-eb

print(comp(add, eadd, stud[0][0], stud[0][1]))
print(comp(sub, esub, stud[1][0], stud[1][1]))
print(comp(mul, emul, stud[2][0], stud[2][1]))
print(comp(div, ediv, stud[3][0], stud[3][1]))
# print(p, ep)