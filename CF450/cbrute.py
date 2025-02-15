n = int(input())
a = [int(i) for i in input().split()]
if (n==1):
    print(1)
    exit()
mp = [-1 for i in range(n+1)]
for i in range(n):
    b = [a[j] for j in range(n) if j != i]
    rec = 1
    high = b[0]
    for j in range(1, n-1):
        if b[j] > high:
            high = b[j]
            rec += 1
        else:
            break
    
    mp[a[i]] = rec

print(mp.index(max(mp)))