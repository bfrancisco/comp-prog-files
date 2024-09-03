from math import ceil
for _ in range(int(input())):
    x, y, k = map(int, input().split())
    a = ceil(x/k)
    b = ceil(y/k)

    # print(a, b)
    if a == b:
        print(a + b)
    elif a < b:
        print(b*2)
    else:
        print(a*2 - 1)