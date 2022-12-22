import sys
n = int(sys.stdin.readline())
a = [sys.stdin.readline() for i in range(n)]
db = set()
for word in a:
    db.add(word[0])
db.add('\n')
# print(a)
# print(db)
pas = True
for i in range(n):
    w = a[i]
    # print(w)
    pas = True
    for c in w:
        if c not in db:
            pas = False
            break
    if pas:
        break
print("Y" if pas else "N")