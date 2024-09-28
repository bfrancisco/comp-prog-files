n = int(input())
has = []
want = []

for i in range(n):
    name, h, w = input().split()
    has.append(h)
    want.append(w)

ans = 0
for i in range(n):
    if has[i] not in want:
        continue
    
    j = want.index(has[i])
    cnt = 1
    noloop = False
    while j != i:
        if has[j] not in want:
            noloop = True
            break
        j = want.index(has[j])
        cnt += 1
    if noloop: continue    
    ans = max(ans, cnt)

print(ans if ans>0 else "No trades possible")