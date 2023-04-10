for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    
    if n == 2:
        if (a[1] < a[0]):
            print("NO")
        else:
            print("YES")
        exit()

    
    