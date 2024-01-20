for _ in range(int(input())):
    h, w, ra, ca, rb, cb = map(int, input().split())
    if (ra >= rb):
        print("Draw")
        continue

    # Alice winning
    if ((rb-ra) % 2):
        if (abs(ca-cb) <= 1):
            print("Alice")
            continue
        if (abs(w-cb) <= (rb-ra)//2):
            print("Draw")
        else:
            print("Alice")

    # Winning Bob
    else:
        if (abs(ca-cb) == 0):
            print("Bob")
            continue
        if (abs(w-ca) <= (rb-ra)//2):
            print("Draw")
        else:
            print("Bob")