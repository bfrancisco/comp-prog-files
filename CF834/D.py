for _ in range(int(input())):
    n, m = map(int, input().split())

    if n%10 == 0:
        x = list(str(m))
        if m < 10:
            print(n*m)
        elif x[0] == '1':
            if int(x[1])%2 == 1:
                x[1] = str(int(x[1]) - 1)
            s = x[0] + x[1] + '0'*(len(x) - 2)
            newm = int(s)
            print(newm*n)
        else:
            if int(x[0])%2 == 1:
                x[0] = str(int(x[0]) - 1)
            s = x[0] + '0'*(len(x) - 1)
            newm = int(s)
            print(newm*n)
    
    elif n%5 == 0:
        x = list(str(m))
        if x[0] != '1':
            if int(x[0]) % 2 == 1:
                x[0] = str(int(x[0]) - 1)
            s = x[0] + '0'*(len(x) - 1)
            newm = int(s)
            #print(x)
            print(n*newm)
        else:
            s = '8' + '0'*(len(x) - 2)
            newm = int(s)
            print(n*newm)
    elif n%10 == 2:
        x = list(str(m))
        if int(x[0]) < 5:
            s = x[0] + '0'*(len(x) - 1)
            newm = int(s)
            print(n*newm)
        else:
            s = '5' + '0'*(len(x) - 1)
            newm = int(s)
            print(n*newm)
    elif n % 2:
        x = list(str(m))
        s = x[0] + '0'*(len(x)-1)
        newm = int(s)
        print(n*newm)
    elif n % 2 == 0:
        if m < 5:
            print(n*m)
        if m < 10:
            print(n*5)
        else:
            x = list(str(m))
            minus = False
            if x[0] != '1' and int(x[0]) % 2 == 1:
                x[0] = str(int(x[0]) - 1)
                minus = True
            if int(x[1]) > 5 or minus:
                x[1] = '5'
            elif int(x[1]) < 5 and not minus:
                x[1] = '0'
            s = x[0] + x[1] + '0'*(len(x)-2)
            newm = int(s)
            #print(x)
            print(n*newm)
    else:
        print(n*m)
    