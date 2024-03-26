from random import randint

t,q,n = map(int, input().split())

qs = [2,3,5,9,17,33,64,126,251,501]
cs = [10, 9,8,7,6,5,4,3,2,1]
MX = 2
for _ in range(t):
    
    printed = False
    l = 0
    r = len(qs)-1
    ans = 1
    while l < r:
        mid = (l+r) // 2
        x = qs[mid]
        names = []
        for i in range(10):
            print("Q", x, flush=True)
            names.append(input())

        same = True
        for name in names:
            if name != names[0]:
                same = False
                break

        if not same:
            r = mid-1
            ans = cs[mid]
        else:
            l = mid+1

    # x = randint(0,1)
    # if x == 0:
    #     same = True
    # else:
    #     same = False
    names = []
    for i in range(MX):
        print("Q", qs[l], flush=True)
        names.append(input())

    same = True
    for name in names:
        if name != names[0]:
            same = False
            break
    
    if same:
        print("A", ans, flush=True)
    else:
        print("A", cs[l], flush=True)

    ok = input()
    if ok == "FAIL":
        exit()
    else:
        continue
