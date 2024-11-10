for _ in range(int(input())):
    n = int(input())
    s = input()
    r = input()

    s1 = s.count('1')
    s0 = s.count('0')
    ans = "YES"
    for i in range(n-1):
        if s1 == 0 or s0 == 0:
            ans = "NO"
            break
        if r[i] == '0':
            s1 -= 1
        else:
            s0 -= 1
    
    print(ans)

