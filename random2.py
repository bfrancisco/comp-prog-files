for _ in range(int(input())):
    B,C,D = map(int, input().split())

    A = 0
    for i in range(61):
        b = (1 << i) & B
        c = (1 << i) & C
        d = (1 << i) & D
        if ((c & ~d) or (~c & d)):
            A |= (1 << i)
    print(A if (A|B) - D == A&C else -1)
