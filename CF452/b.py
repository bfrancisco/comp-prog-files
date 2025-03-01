n = int(input())
a = [int(i) for i in input().split()]

pat = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

ans = "NO"
for spi in range(12):
    pi = spi
    good = True
    for i in range(n):
        if not (a[i] == pat[pi] or (pi == 1 and (a[i]==28 or a[i]==29))):
            good = False
            break
        pi = (pi+1)%12

    if good:
        ans = "YES"
        break

if a.count(29) > 1:
    ans = "NO"
print(ans)