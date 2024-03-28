db = {i:0 for i in range(100001)}
for i in range(1, 100001):
    for d in range(2, i):
        if (i % d == 0):
            db[i] += 1

mx = 0
n = 0
for k, v in db.items():
    if mx < v:
        mx = v
        n = k

print(k, v)
