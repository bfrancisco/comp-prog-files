import sys
sys.stdin=open('Round1.in', 'r')

for _ in range(int(input())):
    n = input()
    if (len(n) == 1):
        print("Yes")
        continue

    db = {}
    for x in n:
        if x not in db:
            db[x] = 1
        else:
            db[x] += 1

    good = True
    for k, v in db.items():
        if v >= 2:
            good = False
            break
    
    print("No" if good else "Yes")