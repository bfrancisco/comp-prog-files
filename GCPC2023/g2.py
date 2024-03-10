s = input()
a = [int(i) for i in s]
n = len(s)

if n == 1:
    print(a[0]+1)
    exit()

ans = [0 for i in range(10)]
for i in range(a[0]):
    ans[i] = n
for i in range(a[0]+1, 10):
    ans[i] = n-1
ans[0] = n-1
for i in range(n):
    if a[i] == a[0]:
        ans[a[0]] += 1

c = n
for i in range(n):
    if a[i] != a[0]:
        break
    c -= 1

# print(ans[a[0]])
ans[a[0]] = max(ans[a[0]], c)

for i in range(n-1):
    if a[0] == a[i]:
        if a[i] == a[i+1]:
            continue
        if a[0] < a[i+1]:
            ans[a[0]] = n
            break
    else:
        break

c2 = 0
for i in range(n):
    if a[i] >= a[0]:
        c2 += 1
ans[a[0]] = max(ans[a[0]], c2)
if (ans[a[0]] < n-1):
    ans[a[0]] = n-1

# print(c)
# print(ans)
print(sum(ans))