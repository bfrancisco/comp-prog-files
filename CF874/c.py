for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    odd, even = 0, 0
    for x in a:
        if x%2:
            odd += 1
        else:
            even += 1
    
    if (odd == 0 or even == 0) or min(a)%2:
        print("YES")
    else:
        print("NO")