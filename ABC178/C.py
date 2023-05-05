mod = 10**9 + 7
n = int(input())
ans = pow(10, n, mod)
ans -= (pow(9, n, mod) + pow(9, n, mod) - pow(8, n, mod))
print(ans % mod)