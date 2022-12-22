def dfs2(char, ans):
    #print(char)
    ans.append(char)
    for next in gr[char]:
        dfs2(next, ans)

def dfs(char, prevset):
    if char in prevset:
        return False
    for neigh in gr[char]:
        if not dfs(neigh, prevset):
            return False
    return True

def check(char, prev):
    prevset = set(prev)
    #print(char, prevset)
    if dfs(char, prevset):
        return False
    return True

def ex():
    # for k, v in gr.items():
    #     print(k, ":", v)
    print("Impossible")
    exit()

n = int(input())
alpha = list("abcdefghijklmnopqrstuvwxyz")
aset = set(alpha)

words = [input() for i in range(n)]

mx = -1
for s in words:
    mx = max(mx, len(s))

gr = {chr(i):[] for i in range(97, 123)}
remaining = set()   # convert to list
vis = {chr(i):0 for i in range(97, 123)}
prev = ''
for i in range(n-1):
    if vis[words[i][0]]:
        if prev != words[i][0]:
            ex()
        remaining.add(i)
        remaining.add(i-1)
    if words[i][0] != words[i+1][0]:
        gr[words[i][0]].append(words[i+1][0])
    prev = words[i][0]
    vis[words[i][0]] = 1


c = 1
while remaining:
    #print(remaining)
    indeces = sorted(list(remaining))
    prev = []
    newrem = set()
    for x in range(len(indeces) - 1):
        i = indeces[x]
        j = indeces[x+1]
        if len(words[i]) <= c:
            continue
        if vis[words[i][c]]:
            if check(words[i][c], prev):
                #print('ey', words[i][c])
                ex()
            if prev and words[i][c] == prev[-1]:
                newrem.add(i)
                newrem.add(indeces[x-1])
        
        if words[i][c] != words[j][c]:
            if check(words[j][c], [words[i][c]]):
                ex()
            gr[words[i][c]].append(words[j][c])
            vis[words[i][c]] = 1
        prev.append(words[i][c])
    c += 1
    remaining = newrem



ans = []
dfs2(words[0][0], ans)

anset = set(ans)
for i in alpha:
    if i not in anset:
        ans.append(i)

for k, v in gr.items():
    print(k, ":", v)
print(*ans, sep='')