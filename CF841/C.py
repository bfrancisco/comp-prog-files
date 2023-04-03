import math
def isperf(x):
    if int(math.sqrt(x) + 0.5) ** 2 == x:
        return True
    return False

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    ans = n*(n+1) // 2
    freq = {}
    #print("initial:", ans)
    val = 0
    for i in range(n):
        val ^= a[i]
        if isperf(a[i]) or val == 0:
            ans -= 1
            #print(a[i])
        if val in freq:
            freq[val] += 1
            ans -= freq[val]
            
        else:
            freq[val] = 1
        
        if a[i] not in freq:
            freq[a[i]] = 1
        else:
            freq[a[i]] += 1

    print(ans)
        