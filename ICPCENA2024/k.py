n = int(input())
words = [input() for i in range(n)]
db = {}
for one in range(n):
    for two in range(one+1, n):
        w1, w2 = words[one], words[two]

        if len(w1) != len(w2): continue

        match = [0 for i in range(len(w1))]
        mstr = ""
        for i in range(len(w1)):
            if w1[i] == w2[i]: 
                match[i] = 1
                mstr += w1[i]
            else:
                mstr += "*"

        if sum(match) != len(w1)-2: continue

        j = match.index(0)
        if match[j] != match[j+1]: continue

        lst = [w1[j:j+2], w2[j:j+2], j, len(w1)]
        if lst[0] > lst[1]:
            lst[0], lst[1] = lst[1], lst[0]
        tp = tuple(lst)
    
        if tp not in db:
            db[tp] = 1
        else:
            db[tp] += 1

ans = 0
for k, v in db.items():
    if v == 1:
        ans += 1
    # print(k, v)
print(ans)

