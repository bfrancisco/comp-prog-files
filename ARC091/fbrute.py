def grundy(a, k):
    s = []
    for v in range(1, a//k + 1):
        s.append(grundy(a-v, k))
    s.sort()
    ret = 0
    for e in s:
        if e != ret:
            break
        ret+=1
    return ret

n = int(input()) 
ans = 0
for i in range(n):
    a, k = map(int, input().split())
    ans ^= grundy(a, k)
print(ans)
print("Takahashi" if ans else "Aoki")