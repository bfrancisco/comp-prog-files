for _ in range(int(input())):
    n = int(input())
    b = [int(i) for i in input().split()]
    a = [b[0]]

    for i in range(1, n):
        if b[i-1] > b[i]:
            a.append(b[i])
        a.append(b[i])
    
    print(len(a))
    print(*a)
