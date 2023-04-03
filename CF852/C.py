for _ in range(int(input())):
    mn, mx = 1, int(input())
    a = [int(i) for i in input().split()]

    l, r = 0, mx-1
    pas = False
    while (r-l >= 3):
        if a[l] == mn:
            mn += 1
            l += 1
        elif a[l] == mx:
            mx -= 1
            l += 1
        elif a[r] == mn:
            mn += 1
            r -= 1
        elif a[r] == mx:
            mx -= 1
            r -= 1
        else:
            pas = True
            break
    if pas: print(l+1, r+1)
    else: print(-1)