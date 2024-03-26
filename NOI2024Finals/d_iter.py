from random import randint

t,q,n = map(int, input().split())

qs = [3,5,9,17,33,64,126,251]
MX = 2
for _ in range(t):
    
    printed = False
    cnt = 9
    for x in qs:
        names = []
        for i in range(MX):
            print("Q", x, flush=True)
            names.append(input())

        same = True
        for name in names:
            if name != names[0]:
                same = False
                break

        if not same:
            print("A", cnt, flush=True)
            printed = True
            break
        cnt -= 1

    if not printed:
        print("A", 1, flush=True)
        

    ok = input()
    if ok == "FAIL":
        exit()
    else:
        continue