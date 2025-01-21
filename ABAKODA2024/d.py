from copy import deepcopy

def compute(n, m, DX, CY):
    a = deepcopy(DX)
    b = deepcopy(CY)
    ret = 0
    l, r = 0, 0
    while (l < n and r < m):
        if (a[l][1] < b[r][1]):
            ret += a[l][0] * b[r][0] * a[l][1]
            b[r][1] -= a[l][1]
            l += 1
        elif (b[r][1] < a[l][1]):
            ret += a[l][0] * b[r][0] * b[r][1]
            a[l][1] -= b[r][1]
            r += 1
        else:
            ret += a[l][0] * b[r][0] * b[r][1]
            l += 1
            r += 1
    return ret
    

for _ in range(int(input())):
    n, m = map(int, input().split())
    X = [int(i) for i in input().split()]
    D = [int(i) for i in input().split()]
    Y = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]

    DX = [[D[i], X[i]] for i in range(n)]
    CY = [[C[i], Y[i]] for i in range(m)]

    DX.sort()
    CY.sort()

    # print(*DX)
    # print(*CY)
    print(compute(n, m, DX, CY), end=" ")

    CY.sort(reverse=True)
    # print(*DX)
    # print(*CY)
    print(compute(n, m, DX, CY))
    

    