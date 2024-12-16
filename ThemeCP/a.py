for _ in range(int(input())):
    n = int(input())
    b = [int(i) for i in input()]

    ans = 0
    for i in range(n-1):
        if b[i] == 0:
            if b[i+1] == 0:
                ans += 2
            elif i+2 < n and b[i+2] == 0:
                ans += 1

    print(ans)