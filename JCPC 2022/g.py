import bisect
# import sys
# sys.stdin=open('milk.in', 'r')

def bisearch(arr, val):
    l, r = 0, len(arr) - 1
    while (r-l > 1):
        mid = (l+r) // 2
        if (arr[mid] == val):
            return mid
        elif arr[mid] < val:
            l = mid
        else:
            r =  mid
    
    if (arr[l] == val):
        return l
    else:
        return r


for _ in range(int(input())):
    n, q = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    d = {}
    d[arr[-1]] = float("inf")
    for x in range(n-2, -1, -1):
        d[arr[x]] = min(arr[x], d[arr[x+1]])
    mx = max(arr)
    arr.sort()
    for i in range(q):
        u,v = [int(x) for x in input().split()]
        if (u > mx or v > mx):
            print("No")
        elif u <= v:
            if v <= mx:
                print("Yes")
            else:
                print("No")
        else:
            # print(arr)
            # print(arr[bisect.bisect_right(arr, u) - 1])
            if d[min(arr[bisearch(arr, u)], u)] <= v:
                print("Yes")
            else:
                print("No")