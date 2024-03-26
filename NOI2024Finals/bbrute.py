
def rec(lst):
    global db
    # print(lst)
    if len(lst) == 1:
        if lst[0] not in db:
            db[lst[0]] = 1
        else:
            db[lst[0]] += 1
        return
    v = len(lst)//2
    for i in range(len(lst)-(v-1)):
        new = lst[:i] + lst[i+v:]
        rec(new)



N = 32

for n in range(1, N+1):
    db = {}
    a = [i for i in range(1, n+1)]
    rec(a)
    b = []
    for k, v in db.items():
        b.append((k, v))
        
    b.sort()
    print(n)
    for x,v in b:
        print(v, end =' ')
    print()