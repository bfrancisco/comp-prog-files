def f(x):
    if x < 2:
        return 1
    return x * f(x-2)

L, R = map(int, input().split())

for n in range(L, R+1, 10):
    s = str(f(n))[::-1]
    c = 0
    for d in s:
        if d == '0':
            c += 1
        else:
            break
    
    print(n, c)