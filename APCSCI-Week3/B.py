def solve(x):
    return x*(x-1) // 2

n = int(input())
a = [int(i) for i in input().split()]

db = {}
for x in a:
    if x not in db:
        db[x] = 0
    else:
        db[x] += 1

ans = 0
for i in range(n-1):
    ans += (n-1-i) - db[a[i]]
    db[a[i]] -= 1
print(ans)