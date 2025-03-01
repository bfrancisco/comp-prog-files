MOD = 998244353

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    v = [0 for i in range(4)]
    v[0] = 1
    for x in a:
        if x==2: 
            v[x] *= 2
            v[x] %= MOD
        v[x] += v[x-1]
        v[x] %= MOD
    
    print(v[3])