for _ in range(int(input())):
    n = int(input())
    b = [int(i) for i in input().split()]
    one = []
    for i in range(n-2):
        if b[i] == 1:
            one.append(i)
    
    ans = "YES"
    for i in range(len(one)-1):
        if one[i+1] - one[i] == 2:
            ans = "NO"
            break
    
    print(ans)