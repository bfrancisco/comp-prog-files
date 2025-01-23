for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    ans = n-1

    # left
    l = 1 
    for i in range(1, n):
        if a[i] == a[0]:
            l += 1
        else:
            break
    
    ans = min(ans, n-l)

    # right
    r = 1
    for i in range(n-2, -1, -1):
        if a[i] == a[-1]:
            r += 1
        else:
            break
    ans = min(ans, n-r)

    # lr
    if a[0] == a[-1]:
        ans = min(ans, n-l-r)
    
    print(max(0, ans))