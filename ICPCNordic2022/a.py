n = int(input())
ali = 0
bob = 0
inps = [input() for i in range(n)]
win = 0
for i in range(n):
    x, y = inps[i].split('-')
    a = int(x)
    b = int(y)
    if (a == 11 and b == 11):
        print("error", i+1)
        exit()

    if ((a+b) % 4 == 1 or (a+b) % 4 == 2):
        a, b = b, a
    
    if (win == 0):
        if (a < ali or b < bob):
            print("error", i+1)
            exit()
    elif win == 1:
        if not (a == 11 and b == bob):
            print("error", i+1)
            exit()
    elif win == 2:
        if not (b == 11 and a == ali):
            print("error", i+1)
            exit()
    
    ali = a
    bob = b
    if ali == 11:
        win = 1
    elif bob == 11:
        win = 2

print("ok")

