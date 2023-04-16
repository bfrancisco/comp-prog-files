for _ in range(int(input())):
    
    s = 'x' + input()
    if s == "x^":
        print(1)
        continue
    ans = 0
    while True:
        n = len(s)
        c = 1
        for i in range(1,n):
            if s[i] == '_':
                if (s[i-1] != '^'):
                    s = s[:i] + '^' + s[i:]
                    ans += 1
                    break
            c += 1
        # print(s[1:])
        
        if c == n:
            break
        
    if (s[-1] == '_'):
        ans+=1
    print(ans)



