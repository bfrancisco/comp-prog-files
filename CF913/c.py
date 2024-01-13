def rec(s):
    reduced = False
    mn = 1000000
    for i in range(len(s)-1):
        if s[i] != s[i+1]:
            reduced = True
            if (i == len(s)-2):
                mn = min(mn, rec(s[0:i]))
            else:
                mn = min(mn, rec(s[0:i] + s[i+2:]))
    
    if (not reduced):
        return len(s)
    
    return mn

for _ in range(int(input())):
    n = int(input())
    s = input()
    print(rec(s))
