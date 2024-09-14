for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()] + [0]

    ans = 0
    done = False
    for i in range(n-1, -1, -1):
        if not done and a[i] > a[i+1]:
            ans = max(ans, a[i])
            done = True
        else:
            ans += 1
    
    print(ans)

