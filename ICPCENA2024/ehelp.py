lst = []
p2 = set()

x = 1
for i in range(1000):
    p2.add(x)
    x *= 2

def C(n):
    return (n//2 if n%2==0 else 3*n+1)

def CS(n):
    global lst
    if n in p2: return
    lst.append(n)
    CS(C(n))

def CST(n):
    global lst
    lst = []
    CS(n)
    s = ""
    for e in lst:
        if e%2==0:
            s += "E"
        else:
            s += "O"
    cpy = [lst[i] for i in range(len(lst))]
    return len(lst), s, cpy

MX = 5000
db = ["" for i in range(MX+1)]

for i in range(1, MX+1):
    sz, s, seq = CST(i)
    suc = False
    for j in range(sz-1):
        if s[j] == s[j+1] and s[j] == "O":
            suc = True
            break
    if sz == 0 or s[-1] == "E" and suc:
        # print(f"{i}\t: INVALID")
        db[i] = "INVALID"
    else:
        # print(f"{i}\t: {s} {list(reversed(seq))}")
        db[i] = s

pttern = input()
for i in range(MX+1):
    if db[i] == pttern:
        print(i)