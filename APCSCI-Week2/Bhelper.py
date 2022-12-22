def merge(left, right, lsz, rsz):
    ret = []
    i, j = 0, 0
    while i < lsz and j < rsz:
        if left[i] <= right[j]:
            ret.append(left[i])
            i += 1
        else:
            ret.append(right[j])
            j += 1
    #print(left, right)
    ret += left[i:]
    ret += right[j:]
    #print(ret)
    #print()
    return ret
 
def mergesort(a, n, count):
    if n <= 1 or a == sorted(a):
        return a, count

    mid = n//2
    Lsz = mid
    Rsz = mid+1 if n%2 else mid

    L, count = mergesort(a[:mid], Lsz, count+1)
    R, count = mergesort(a[mid:], Rsz, count+1)
    print(L, R)
    LR = merge(L, R, Lsz, Rsz)
    return LR, count

#n, k = map(int, input().split())
n = 5
#c = [i for i in range(n, 0, -1)]
c = [3,1,4,2,5]
d, k = mergesort(c, n, 1)
print(k)