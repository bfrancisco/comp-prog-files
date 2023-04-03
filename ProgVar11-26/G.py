fibo = [1,1]
for x in range(1,101):
    fibo.append(fibo[x] + fibo[x-1])
n = int(input())
a = n
if n == 1:
    print("B")
    exit()
fibo.sort(reverse=True)
fibo_factors = []
for x in fibo:
    if x == 1:
        continue
    if n%x == 0:
        while n%x == 0:
            fibo_factors.append(x)
            n //= x
check = 1
for x in fibo_factors:
    check *= x
if check != a:
    print("IMPOSSIBLE")
    exit()
fibo.sort()
if len(fibo_factors) == 0:
    print("IMPOSSIBLE")
    exit()
else:
    for x in fibo_factors:
        num = fibo.index(x)
        print('A'*(num-1) + "B", end='')