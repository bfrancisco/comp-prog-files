n, m = input().split()
ans = 1
while (n != m and (len(n) <= 100) and ans <= 100):
    db = [0]*10
    for c in n:
        db[int(c)] += 1

    new = ""
    for i in range(10):
        if (db[int(i)] > 0):
            new += str(db[i]) + str(i)
    
    n = new
    ans += 1

if (n == m):
    print(ans)
elif len(n) >= 100:
    print("I’m bored")
else:
    print("Does not appear")