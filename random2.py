for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = "NO"
    for i in range(n-1):
        if s[i] == s[i+1] and s[i] == '1':
            ans = "YES"
            break
    if s[0] == '1' or s[-1] == '1':
        ans = "YES"
    print(ans)
