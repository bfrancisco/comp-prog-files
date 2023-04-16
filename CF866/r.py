for _ in range(int(input())):
    s = 'xx' + input() + 'xx'
    n = len(s)
    prev = 'x'
    prev2 = 'x'
    ans = 0
    for i in range(1, n-1):
        if (s[i] == '_'):
            if (prev == '^' and s[i+1] == '^'):
                continue

            if (prev != '^'):
                ans += 1
            if (s[i+1] != '^'):
                ans += 1
                prev = '^'
        elif (s[i] == '^'):
            if prev == '^' or s[i+1] == '^':
                continue

            if prev != '^':




