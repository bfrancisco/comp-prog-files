for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    if max(a) != n:
        print("NO")
        continue
    dif = [0 for i in range(n+2)]
    for e in a:
        dif[1] += 1
        dif[e+1] -= 1

    # print(dif)
    pref = [0 for i in range(n+2)]
    pref[1] = dif[1]
    for i in range(2, n+2):
        # print(i)
        pref[i] = pref[i-1] + dif[i]

    print("YES" if pref[1:-1] == a else "NO")
    
    # print(pref)


