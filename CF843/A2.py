for _ in range(int(input())):
    s = input()

    n = len(s)
    pas = False
    for i in range(1, n-1):
        if s[i] == 'a':
            print(s[:i], 'a' , s[i+1:])
            pas = True
            break
    if pas:
        continue
    
    firstb = 1
    for i in range(1, n-1):
        if s[i] == 'b':
            break
    
    a = s[0:firstb]
    b = s[firstb:n-1]
    c = s[n-1]
    if (b >= a and b >= c):
        print(a,b,c)
    else:
        print(":(")