n = int(input())

ans = 0
for d in range(1, int(n**(1/2)) + 2):
    if n % d == 0 and d % 2 == 1:
        ans += 2
        if n//d - (d//2) == 1:
            ans += 2
    elif n/d - 0.5 == n//d:
        ans += 2
        if (n//d + 1) - d//2 == 1:
            ans += 2
 
print(ans)