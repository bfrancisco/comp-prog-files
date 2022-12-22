def f(x):
    # inverse x = n*(n+1)/2
    r = (2*x + (1/4))**(1/2) - (1/2)
    return r

def f2(x):
    return x*(x+1) // 2

n = 1000000000
print(f2(n))
# limit = n + f2(n)
i = 500000001500000000
print(f(i))

