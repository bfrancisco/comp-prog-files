from math import gcd

def f(n):
    c = 0
    for i in range(2, n+1):
        if gcd(i, n) > 1:
            c+= 1
    return c

# 2 	    2        1/2
# 6 	    6 	     4/6
# 30 	    30 	     22/30
# 210 	    210 	 162/210
# 2310 	    2310 	 1830/2310
# 30030 	30030 	 24270/30030


L, R = 30030, 30030
prev = -1
for N in range(L, R+1):
    mx = 0
    num = -1
    denom = -1
    for n in range(2, N+1):
        fn = f(n)
        gn = fn / n
        
        if (mx < gn):
            mx = gn
            num = fn
            denom = n

    g = gcd(num, denom)

    if (prev == denom):
        continue
    prev = denom
    print(N, '\t', denom, '\t', str(num)+"/"+str(denom))
    # print(N, num, denom, mx)
    # print(num // g, '/', denom // g, sep='')