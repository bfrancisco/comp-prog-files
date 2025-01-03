words = ["squawk", "chirp", "quack"]
db = {ch:0 for ch in "squawkchirp"}

pnts = [[int(i), '-'] for i in input().split()]
pnts[0][1], pnts[1][1], pnts[2][1] = 0, 1, 2
s = input()
pnts.sort(reverse=True)

for ch in s:
    if ch in db:
        db[ch] += 1

print(pnts)
for k, v in db.items():
    print(f'{k} : {v}')
print()
ans = {word:0 for word in words}
for pnt, wordi in pnts:
    word = words[wordi]
    if word == "squawk":
        while db['s'] > 0 and db['q'] > 0 and db['u'] > 0 and db['a'] > 0 and db['w'] > 0 and db['k'] > 0:
            for ch in word:
                db[ch] -= 1
            ans[word] += 1
    elif word == "chirp":
        while db['c'] > 0 and db['h'] > 0 and db['i'] > 0 and db['r'] > 0 and db['p'] > 0:
            for ch in word:
                db[ch] -= 1
            ans[word] += 1
    elif word == "quack":
        while db['q'] > 0 and db['u'] > 0 and db['a'] > 0 and db['c'] > 0 and db['k'] > 0:
            for ch in word:
                db[ch] -= 1
            ans[word] += 1

    for k, v in db.items():
        print(f'{k} : {v}')
    print()

print(ans)
for k, v in ans.items():
    print((k+" ")*v, end= "")
print()
    
        


