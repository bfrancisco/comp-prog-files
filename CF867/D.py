for _ in range(int(input())):
    n = int(input())
    if n==1:
        print(1)
        continue
    if(n%2):
        print(-1)
        continue

    a = [0 for i in range(n)]
    a[0] = n
    a[n//2] = n//2
    con = 1
    val = n-1
    for i in range(1, n//2):
        if con == 1:    # go down
            a[i] = a[i-1] - val
        else:
            a[i] = a[i-1] + val
        val -= 2
        con = 1-con
    
    con = 0
    if (a[n//2 - 1] > n//2):
        con = 1
    val = 1

    for i in range(n//2 + 1, n):
        if con == 1:
            a[i] = a[i-1] - val
        else:
            a[i] = a[i-1] + val
        val += 2
        con = 1-con

    print(*a)



