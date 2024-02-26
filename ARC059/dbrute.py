def brute():
    s = input()
    n = len(s)
    for i in range(n):
        for j in range(i+1, n):
            db = {}
            for c in s[i:j+1]:
                if c not in db:
                    db[c] = 1
                else:
                    db[c] += 1

            ln = j-i+1
            for k, v in db.items():
                if v > ln//2:
                    return "Y"
    return "N"

print(brute())
                        
