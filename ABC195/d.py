n,m,q = map(int, input().split())
db = []
for i in range(n):
    w, v = map(int, input().split())
    db.append((w, v, i))
db.sort()

bi = [int(i) for i in input().split()]
box = [(bi[i], [], i) for i in range(m)]

for i in range(m):
    sz = box[i][0]
    for w, v, ind in db:
        if sz >= w:
            box[i][1].append((v, ind))

for i in range(m):
    box[i][1].sort(reverse=True)
    # print(box[i])
box.sort()

for _ in range(q):
    l, r = map(int, input().split())
    ans = 0
    bank = set()
    for i in range(m):
        if l <= box[i][2]+1 and box[i][2]+1 <= r:
            continue
        # print(box[i])
        for val, ind in box[i][1]:
            if ind not in bank:
                bank.add(ind)
                ans += val
                break
    print(ans)
    