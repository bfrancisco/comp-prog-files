from itertools import permutations

def lis_lds(a):
    dplis = [1 for i in range(len(a))]
    dplds = [1 for i in range(len(a))]
    lis, lds = 1, 1
    for i in range(len(a)):
        for j in range(i):
            if a[i] > a[j]: dplis[i] = max(dplis[i], dplis[j]+1)
            if a[i] < a[j]: dplds[i] = max(dplds[i], dplds[j]+1)
        lis = max(lis, dplis[i])
        lds = max(lds, dplds[i])
    return lis, lds

def good(n,a,b):
    for p in permutations([i for i in range(1, n+1)]):
        lis, lds = lis_lds(p)
        if (lis==a and lds==b):
            return True
    return False

# n, a, b = map(int, input().split())
n = 7
for a in range(1, n+1):
    for b in range(1, n+1):
        if good(n,a,b):
            print(f"GOOD: ({a}, {b}) , {a+b}")