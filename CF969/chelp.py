from math import gcd

for _ in range(int(input())):
    n, a, b = map(int, input().split())
    v = [int(i) for i in input().split()]
    v.sort()
    g = gcd(a, b)

    vv = [e%g for e in v]
    va = [e%a for e in v]
    vb = [e%b for e in v]
    ve = []
    print(vv)
    ans = [
        min(max(vv) - min(vv) , (vv[-2]+g) - vv[-1]), 

    ]
    # print(min(max(vv) - min(vv) , (vv[-2]+g) - vv[-1]))
    print(min(ans))
