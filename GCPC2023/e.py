s = input().lower()
ans = [s]
n = len(s)
s += " "
for i in range(n-1):
    if (s[i] == 's' and s[i+1] == 's'):
        ans.append(s[:i] + 'B' + s[i+2:])

print(*ans, sep='\n')

