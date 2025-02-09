n, s = map(int, input().split())

print(n + min(s-1, n-s) + (n-1) + (n+1))