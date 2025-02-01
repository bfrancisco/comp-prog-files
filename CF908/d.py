for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(i) for i in input().split()] + [0]
    b = [int(i) for i in input().split()]

    b.sort()
    ans = []
    for i in range(n+1):
        while b and b[-1] >= a[i]:
            ans.append(b[-1])
            b.pop()
        ans.append(a[i])
    
    print(*ans[:-1])