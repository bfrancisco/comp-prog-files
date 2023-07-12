db = {}

while (True):
    row = input()
    if (row == "end"):
        break
    carat, cut = row.split(',')
    if cut not in db:
        db[cut] = [carat]
    else:
        db[cut].append(carat)

for cut, carats in db.items():
    print("CUT:", cut)
    for c in carats:
        print(c)
    