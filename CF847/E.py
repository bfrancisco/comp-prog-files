p = []
for e in range(0, 30):
    p.append(pow(2, e))

for _ in range(int(input())):
    n = int(input())

    i = 0
    p2 = -1
    while i < 30 and n >= p2:
        p2 = p[i]
        i+=1
    # print(p2)
    b = p2 - 1
    a = n ^ b
    print(a, b)
    if (a ^ b == (a+b)/2):
        print(a, b)
    else:
        print(-1)

    