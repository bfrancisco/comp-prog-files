def f(val, l):
    if (val == l*(l+1)/2):
        return True
    return False
def f(val, l):
    if (val == l*(l+1)/2):
        return True
    return False

for _ in range(int(input())):
    n = int(input())
    z = [int(i) for i in input().split()]
    zz = z.index(2)
    z1 = z.index(1)
    a = []
    b = []
    c = []
    d = []
    for i in range(n):
        a.append(z[i])
        b.append(z[i])
        c.append(z[i])
        d.append(z[i])

    a[zz], a[0] = a[0], a[zz]
    b[zz], b[-1] = b[-1], b[zz]
    c[z1], c[0] = c[0], c[z1]
    d[z1], d[-1] = d[-1], d[z1]

    A, B, C, D = 0, 0, 0, 0
    co = 2
    sz = 1
    for e in a[1:]:
        co += e
        sz += 1
        if f(co, sz):
            A+=1
    
    co = 2
    sz = 1
    for e in b[-2::-1]:
        co += e
        sz += 1
        if f(co, sz):
            B+=1

    co = 1
    sz = 1
    for e in c[1:]:
        co += e
        sz += 1
        if f(co, sz):
            C+=1
    
    co = 1
    sz = 1
    for e in d[-2::-1]:
        co += e
        sz += 1
        if f(co, sz):
            D+=1
    
    # print(A, B, C, D)
    mn = min(A,B,C,D)
    if A == mn:
        print(zz+1, 1)
    elif B == mn:
        print(zz+1, n)
    elif C == mn:
        print(z1+1, 1)
    elif D == mn:
        print(z1+1, n)