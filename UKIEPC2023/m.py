a, b, c = map(int, input().split())

ans = 0 
if c >= 2:
    ans += 2*b+3
    c -= 2

ans += c//2 *3
ans += 2*a
print(ans)