for _ in range(int(input())):
    n = int(input())
    s = list(input())
    l = s[0]
    ind = 0

    for i in range(1, n):
        if s[i] <= l:
            ind = i
            l = s[i]
    
    print(l, end = '')
    for i in range(n):
        if i == ind:
            continue
        print(s[i], end = '')
    print()
