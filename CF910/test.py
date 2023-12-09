def f(a,b):
    return (2**a)**(2**b) == (2**b)**(2**a)

# a, b = map(int, input().split())

for a in range(1, 100):
    for b in range(a+1, 100):
        if (f(a, b)):
            print(a, b)