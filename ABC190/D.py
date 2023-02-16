def f(sm, n):
    if (2*sm / n - n + 1) % 2 == 0:
        return 2

    return 0

sm = int(input())

ans = 0
for i in range(1, int((2*sm)**(1/2)) + 1):
    ans += f(sm, i)
    
print(ans)