from math import gcd
n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
ans = 0
for i in range(n):
    if a[i]==0: 
        if b[i]==0: ans += 1
    
    elif abs(a[i])==1 or abs(b[i])==1:
        ans += 1
    elif b[i]==0 or abs(gcd(a[i], b[i])) > 1:
        ans += 1
print(ans)
