s = input()
a = [int(i) for i in s]
n = len(s)

if n == 1:
    print(a[0]+1)
    exit()

ans = [0 for i in range(10)]
ans[0] = n-1

for x in range(1, 10):
    if x > a[0]:
        ans[x] = n-1
        continue
    greater = False
    for i in range(n):
        if greater:
            ans[x] += 1
        elif a[i] > x:
            greater = True
            ans[x] += 1
        elif a[i] == x:
            ans[x] += 1
        else:
            pass
        if (x == 6):
            print(ans[6])

print(ans)
print(sum(ans))