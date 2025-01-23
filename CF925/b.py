for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    val = sum(a)//n
    sobra = 0
    pas = True
    for i in range(n):
        if a[i] > val:
            sobra += a[i] - val
        elif a[i] < val:
            if val - a[i] > sobra:
                pas = False
                break
            else:
                sobra -= (val - a[i])
    
    print("YES" if pas else "NO")
