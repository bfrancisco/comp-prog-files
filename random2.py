s = input()
n = len(s)

for rpad in range(n):
    pattern = s[:rpad]
    for lrep in range(1, min(rpad, n-len(pattern)+1)):
        if pattern == s[lrep:lrep+len(pattern)] and lrep+len(pattern) == n:
            print("YES")
            print(pattern)
            exit()
print("NO")