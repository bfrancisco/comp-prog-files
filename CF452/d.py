n = int(input())
ans = n*(n-1)//2
for e in range(1, 10):
    ten = 10**e
    if n == ten-1:
        ans = ten//2 - 1
    elif n >= ten//2:
        ans = n - ten//2 + 1 if n < ten-1 else ten//2 + n-ten
print(ans)