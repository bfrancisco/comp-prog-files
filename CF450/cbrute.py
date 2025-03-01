n = int(input())
a = [int(i) for i in input().split()]
if (n==1):
    print(1)
    exit()
mp = [-1 for i in range(n+1)]
for i in range(n):
    b = a[:i] + a[i+1:]
    # print(b)
    rec = 0
    high = 0
    # print(f'high: {high}')
    for j in range(n-1):
        if b[j] > high:
            high = b[j]
            rec += 1
    # print(f'high: {high}')
    # print(f"rem: {a[i]}, record: {rec}")
    mp[a[i]] = rec

# print(mp)
print(mp.index(max(mp)))