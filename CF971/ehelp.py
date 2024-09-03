def f(l, m, r):
    return int((m-l+1)/2*(l+m)) - int((r-(m+1)+1)/2*((m+1)+r))

L, R = 2, 2+7-1
mn = 1e18
z = -1
for i in range(L, R+1):
    if mn > abs(f(L, i, R)):
        mn = abs(f(L, i, R))
        z = i

print(f(L, 6, R))
print(z, mn)