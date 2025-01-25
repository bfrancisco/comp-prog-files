for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [int(i) for i in input().split()]
    last = n-1
    pas = True
    for i in range(min(n, k)):
        # print(last, a[last])
        
        if a[last] > n:
            pas = False
            break
    
        last = (last - a[last]) % n
    
    print("Yes" if pas else "No")