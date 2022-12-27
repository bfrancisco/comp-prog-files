for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    a.sort()
    i = n-1
    #print(a)
    while i >= 0:
        if i-1 >= 0 and a[i] != 1 and a[i-1] != 1:
            a[i] = a[i] * a[i-1]
            a[i-1] = 1
            i -= 2
        else:
            i -= 1
    #print(a)
    for i in range(n-1):
        if a[i] != 1:
            a[n-1] = a[i] * a[n-1]
            a[i] = 1
            
    print(2022 * sum(a))
         