a,b,c = map(int, input().split())

s = ""
dec = False
for _ in range(10000):
    if a < b:
        a *= 10
        if not dec:
            s += '.'
            dec = True
    
    if a == 0:
        s += '0'
    else:
        s += str(a//b)
        a = a%b

t = 1
ans = -1
for i in range(s.index('.')+1, len(s)):
    if s[i] == str(c):
        ans = t
        break
    t += 1

print(ans)
