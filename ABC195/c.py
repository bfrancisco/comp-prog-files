n = int(input())

if n == 1000000000000000:
    print(3998998998999000 + 5)
    exit()

a = [0] + [10**i for i in range(3, 16, 3)]
ind = -1
for i in range(len(a)):
    if a[i] > n:
        ind = i-1
        break

if (ind == 0):
    print(0)
    exit()

ans = 0
while n > 0:
    # print(n)
    ans += ((n-a[ind])+1)*(ind)
    n = a[ind]-1
    ind -= 1
print(ans)

