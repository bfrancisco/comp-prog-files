from collections import deque

def ex():
    print("Impossible")
    exit()

n = int(input())
alpha = list("abcdefghijklmnopqrstuvwxyz")

words = [input() for i in range(n)]
gr = {chr(i):[] for i in range(97, 123)}
indeg = {chr(i):0 for i in range(97, 123)}
irel = set(alpha)
for i in range(n-1):
    j = 0
    fi = words[i]
    se = words[i+1]
    a = len(fi)
    b = len(se)

    while j < a and j < b and fi[j] == se[j]:
        j += 1
    
    if j >= b:
        ex()
    elif j < a:
        gr[fi[j]].append(se[j])
        indeg[se[j]] += 1
        # irel.remove(fi[j])
        # irel.remove(se[j])

# for k, v in gr.items():
#     print(k , v)
# check cycles

que = deque([])
ans = []
for char in alpha:
    if not indeg[char]:
        que.append(char)
        ans.append(char)

while que:
    v = que.popleft()
    for next in gr[v]:
        indeg[next] -= 1
        if not indeg[next]:
            que.append(next)
            ans.append(next)

print(''.join(ans) if len(ans) == 26 else "Impossible")