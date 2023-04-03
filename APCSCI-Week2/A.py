def merge(left, right, lsz, rsz):
    ret = []
    i, j = 0, 0
    inv = 0
    while i < lsz and j < rsz:
        if left[i] <= right[j]:
            ret.append(left[i])
            i += 1
        else:
            ret.append(right[j])
            j += 1
            inv += lsz - i
    #print(left, right)
    ret += left[i:]
    ret += right[j:]
    #print(ret)
    #print()
    return ret, inv
 
def mergesort(a, n):
    if n <= 1:
        return [a, 0]
    mid = n//2
    Lsz = mid
    Rsz = mid+1 if n%2 else mid
    L, invL = mergesort(a[:mid], Lsz)
    R, invR = mergesort(a[mid:], Rsz)
    LR, invs = merge(L, R, Lsz, Rsz)
    invs += invL + invR
    return LR, invs
 
for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
 
    db = {}
    for i in range(n):
        db[a[i]] = i
 
    c = [db[x] for x in b]
    #print(c)
    print(mergesort(c, n)[1])