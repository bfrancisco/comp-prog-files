for _ in range(int(input())):
    n = int(input())
    s = input()
 

    divs = [d for d in range(1, n+1) if n%d==0]
    ans = n
    for d in divs:
        bank = set()
        for i in range(0, n, d):
            bank.add(s[i:i+d])
            if (len(bank) == 3): 
                break
        print(d)
        print(bank)
        
        if (len(bank) == 1):
            ans = d
            break

        if (len(bank) == 2):
            z = []
            for e in bank:
                z.append(e)
            wrong = 0
            for j in range(len(z[0])):
                if z[0][j] != z[1][j]:
                    wrong += 1
            if wrong <= 1:
                ans = d
                break


    print(ans)