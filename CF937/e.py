for _ in range(int(input())):
    n = int(input())
    s = input()
 
    ans = n
 
    db = {}
    for c in s:
        if c not in db:
            db[c] = 1
        else:
            db[c] += 1
 
    if (len(db)==2):
        for k, v in db.items():
            if v==1:
                ans = 1
                break
    
    if ans == 1:
        print(ans)
        continue
 
    divs = [d for d in range(2, n) if n%d==0]
    for d in divs:
        bank = set()
        for i in range(0, n, d):
            bank.add(s[i:i+d])
        # print(d)
        # print(bank)
        
        if (len(bank) <= 2 and n//d != 2):
            ans = min(ans, d)
            break
        if (n//d == 2 and len(bank) == 2):
            z = []
            for e in bank:
                z.append(e)
            wrong = 0
            for j in range(len(z[0])):
                if z[0][j] != z[1][j]:
                    wrong += 1
            if wrong <= 1:
                ans = min(ans, d)
                break
        elif (n//d == 2 and len(bank) == 1):
            ans = min(ans, d)
            break
 
    print(ans)