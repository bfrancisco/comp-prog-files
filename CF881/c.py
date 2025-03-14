for _ in range(int(input())):
    n = int(input())
    ans = 0
    while n:
        ans += n
        n >>= 1
    print(ans)