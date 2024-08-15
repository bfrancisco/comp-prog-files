for _ in range(int(input())):
    n = int(input())
    s = list(input())
    ans = 0
    c = 0
    prevop = -1
    for i in range(n):
        if s[i] == '_':
            if c == 0:
                s[i] = '('
                c += 1
            elif c > 1:
                s[i] = ')'
                c -= 1
        elif s[i] == '(':
            c += 1
        else:
            c -= 1
    
    # print("".join(s))

    q = [0]
    ans = 0
    for i in range(1,n):
        if s[i] == '(':
            q.append(i)
        else:
            ans += i-q[-1]
            q.pop()
    
    print(ans)
            

    
