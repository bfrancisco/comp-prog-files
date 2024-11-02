from bisect import bisect_left

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    a.sort()
    ans = 1e9
    for i in range(n-1):
        val = i
        ind = bisect_left(a, a[i]+a[i+1])
        ans = min(ans, i + (n-ind))
    
    print(ans)