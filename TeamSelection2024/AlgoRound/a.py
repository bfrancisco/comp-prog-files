from math import sqrt

DIV = 100000000000

def dist(a,b,c,d):
    return sqrt(abs(a-c)**2 + abs(b-d)**2)


N = int(input())
X = [0 for i in range(N)]
Y = [0 for i in range(N)]
T = [0 for i in range(N)]

for i in range(N):
    x,y,t = map(int, input().split())
    X[i] = x
    Y[i] = y
    T[i] = t

M = float(input())

def can(intv):
    v = intv / DIV

    db = []
    x,y = 0,0
    for i in range(N):
        db.append((T[i], dist(x,y,X[i],Y[i]), X[i], Y[i]))
    
    # sort by time --> distance. lowest time lowest distance sa huli
    db.sort(reverse=True)
    
    timeTaken = 0
    while db:
        t, d, cx, cy = db[-1]
        db.pop()
        timeTaken += d/v
        if t-timeTaken < 0.00001:
            return False

        v *= M

        next_db = []
        x, y = cx, cy
        for i in range(len(db)):
            next_db.append((db[i][0], dist(x,y,db[i][2],db[i][3]), db[i][2],db[i][3]))
        
        next_db.sort(reverse=True)
        db = next_db
    
    return True


l = 1
r = 10**15
want = -1
while l < r:
    mid = l + (r-l)/2

    if (can(mid)):
        r = mid
    else:
        l = mid+1
        want = mid+1

RANG = 10000 
for z in range(-RANG, RANG+1):
    if can(want+z):
        want = want+z
        break

print(want / DIV - 0.0001)