def isvalid(x):
    if L <= x and x <= R:
        return True
    return False

def rec(n, l, r):
    global ans
    #print(l, r)
    if l > R or r < L:
        return
    if l == r:
        if isvalid(l):
            ans += 1
        return
    mid = (l+r)//2
    if n%2 and isvalid(mid):
        ans += 1
    rec(n//2, l, mid-1)
    rec(n//2, mid+1, r)


N,L,R = map(int, input().split())
if N == 0:
    print(0)
    exit()
l, r = 1, 2**(len(bin(N)) - 2)-1
ans = 0
rec(N, l, r)
print(ans)