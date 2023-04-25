for _ in range(int(input())):
    n = int(input())
    s = input()
    if n%2:
        print(-1)
        continue

    db = {}
    for x in s:
        if x not in db:
            db[x] = 1
            
        else:
            db[x] += 1
    lets = set(db.keys())
    
    anti = {}
    
    for i in range(n//2):
        if s[i] == s[-(i+1)]:
            if s[i] not in anti:
                anti[s[i]] = 1
            else:
                ant[s[i]] += 1

    

    print(*antis)
                
