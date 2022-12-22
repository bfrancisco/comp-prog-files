from collections import deque

def ex():
    print("Impossible")
    exit()

def bfscheck(a, b, gr):
    # check if a will go to b. if it will, return false
    q = deque([a])
    vis = {chr(i):0 for i in range(97, 123)}
    vis[a] = 1
    while q:
        cur = q.popleft()
        for next in gr[cur]:
            if next == b:
                return False
            if not vis[next]:
                q.append(next)
                vis[next] = 1
    return True

def dfs(cur, ans, gr, visdfs):
    if visdfs[cur]:
        return
    stack = [cur]
    visdfs[cur] = 1
    while stack:
        #print(stack)
        v = stack.pop()
        ans.append(v)
        for next in gr[v]:
            if not visdfs[next]:
                visdfs[next] = 1
                stack.append(next)

def main():
    n = int(input())
    alpha = list("abcdefghijklmnopqrstuvwxyz")
    aset = set(alpha)

    words = [input() for i in range(n)]
    gr = {chr(i):[] for i in range(97, 123)}

    query = deque([[0, n-1, 0]])
    firstchars = []
    while query:
        l, r, c = query.popleft()
        toq = [l, 0]
        #print(l, r, c)
        isfirst = False
        
        for i in range(l, l+r):
            fi = words[i]
            se = words[i+1]
            #print(fi, se)
            if len(se) <= c and len(fi) > c:
                ex()
            if len(fi) <= c:
                continue

            if fi[c] == se[c]:
                toq[1] += 1
                continue
            elif fi[c] != se[c]:
                if toq[1] > 0:
                    query.append(toq + [c+1])
                toq = [i+1, 0]
            
            if bfscheck(se[c], fi[c], gr):
                gr[fi[c]].append(se[c])
                isfirst = True
            else:
                ex()
        if toq[1] > 0:
            query.append(toq + [c+1])

        if isfirst:
            firstchars.append(words[l][c])
        

        
    # for k, v in gr.items():
    #     print(k, v)

    ans = []
    #print(firstchars)
    visdfs = {chr(i):0 for i in range(97, 123)}
    for char in firstchars:
        dfs(char, ans, gr, visdfs)

    #print(*ans, sep='')
    anset = set(ans)
    for i in alpha:
        if i not in anset:
            ans.append(i)

    print(*ans, sep='')

main()