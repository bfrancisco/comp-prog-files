def ms(l, r):
    global c
    if l == r or c == 0:
        return 
        
    mid = (l+r+1)//2

    temp = a[mid]
    a[mid] = a[mid-1]
    a[mid-1] = temp
    c -= 1

    ms(l, mid-1)
    ms(mid, r)

    return 


n, k = map(int, input().split())
if not k % 2 or k > 2*n:
    print(-1)
    exit()

a = [i for i in range(1,n+1)]
c = (k-1)//2
ms(0, n-1)
print(*a)
