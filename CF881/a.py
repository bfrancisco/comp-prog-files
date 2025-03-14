for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    ans = 0
    a.sort()
    for i in range(n//2):
        ans += a[-i-1] - a[i]
    print(ans)