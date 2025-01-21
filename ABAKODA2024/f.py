n, q = map(int, input().split())

maybe = set()
no = set()

for _ in range(q):
    m = int(input())
    coins = set([int(i) for i in input().split()])
    w = int(input())

    if w%2:
        if maybe:
            # maybe = maybe & coins
            torem = []
            for c in maybe:
                if c not in coins:
                    torem.append(c)
                    no.add(c)
            for c in torem:
                if c in maybe: maybe.remove(c)
        else:
            for c in coins:
                if c not in no: 
                    maybe.add(c)
    else:
        for c in coins:
            no.add(c)
            if c in maybe: maybe.remove(c)
    
    # print(f"maybe: {maybe}")
    # print(f"no   : {no}")
    # print()

if len(maybe) == 1 or len(no) == n-1:
    print(1, n-1, 0)
else:
    if len(maybe) == 0:
        print(0, len(no), n-len(no))
    else:
        print(0, n-len(maybe), len(maybe))