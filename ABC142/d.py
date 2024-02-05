a, b = map(int, input().split())
if (a > b):
    zz = a
    a = b
    b = zz

divs = []
for d in range(1, min(int(a**(1/2)), 10**6)+1):
    if (a%d == 0 and b%d == 0):
        divs.append(d)
        if (d*d != a and b % (a//d) == 0):
            divs.append(a//d)
        if (a % (b//d) == 0):
            divs.append(b//d)
divs.sort()
print(divs)