for _ in range(int(input())):
    n = int(input())
    x = n*(n+1)*(4*n - 1) // 6
    print((2022 * x) % 1000000007)