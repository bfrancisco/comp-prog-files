def f(x):
    return x*(x-1)//2
# for i in range(1, 30):
#     print(i, ":", f(i))

for _ in range(int(input())):
    l, r = 1, 2648956421
    n = int(input())
    ans = -1
    while l < r:
        m = (l+r)//2
        if f(m) <= n:
            l = m+1
            ans = m
        else:
            r = m

    print(ans + (n - f(ans)))