for _ in range(int(input())):
    N, R, K = map(int, input().split())

    k = K//N
    r = R//N

    KN, NKN = K%N, N-(K%N)
    RN, NRN = R%N, N-(R%N)

    ans = 0
    ans += min(KN, NRN)*(k+1)*r
    if KN < NRN:
        ans += (NRN - KN)*k*r
        ans += RN*k*(r+1)
    elif KN > NRN:
        ans += (KN - NRN)*(k+1)*(r+1)
        ans += NKN*k*(r+1)
    elif KN == NRN:
        ans += NKN*k*(r+1)

    print(ans)