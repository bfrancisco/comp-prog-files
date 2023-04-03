for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    ans = -1
    for x in range(0, 256):
        b = [v ^ x for v in a]
        c = 0
        for z in b:
            c ^= z
        if c == 0:
            ans = x
            break
    print(ans)