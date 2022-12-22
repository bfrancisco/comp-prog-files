def count(a):
    zeros = a.count(0)
    ans = 0
    for i in a:
        if i == 0:
            zeros -= 1
        else:
            ans += zeros
    return ans

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    s = set(a)
    out = []
    out.append(count(a))
    if 0 in s:
        ind = -1
        for i in range(n):
            if a[i] == 0:
                a[i] = 1
                ind = i
                break
        out.append(count(a))
        a[ind] = 0

    
    if 1 in s:
        for i in range(n-1, -1, -1):
            if a[i] == 1:
                a[i] = 0
                break
        out.append(count(a))
    
    print(max(out))
