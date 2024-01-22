N = 201
dp = [-1 for i in range(N)]

def grundy(a, k):
    if (dp[a] != -1):
        return dp[a]
    
    s = []
    for v in range(1, a//k + 1):
        s.append(grundy(a-v, k))
    s.sort()
    ret = 0
    for e in s:
        if e != ret:
            break
        ret+=1
    dp[a] = ret
    return ret

# a, k = map(int, input().split())
k = 3
for a in range(1, N):
    g = grundy(a, k)
    if a%3:
        print(f"{a}\t:\t{g}")