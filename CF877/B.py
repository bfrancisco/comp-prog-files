def f(val, l):
    if (val == l*(l+1)/2):
        return True
    return False

for _ in range(int(input())):
    n = int(input())
    z = [int(i) for i in input().split()]
    

    a = []
    for i in range(n):
        if z[i] != 2:
            a.append(z[i])

    s = set()
    A, B = 0, 0
    
    c = 1
    sz = 1
    for e in a:
        c += e
        sz += 1
        if f(c, sz):
            A+=1

    c = 1
    sz = 1
    for e in a[::-1]:
        c += e
        sz += 1
        if f(c, sz):
            B+=1
    print(A, B)
    if A <= B:
        print(1, z.index(1)+1)
    else:
        print(n, z.index(1)+1)
    
