for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    odd = []
    even = []
    for i in range(n):
        if a[i] % 2 == 0:
            even.append(i+1)
        else:
            odd.append(i+1)
    
    x, y = len(odd), len(even)
    # print(x, y)
    if x >= 3:
        print("YES")
        print(odd[0], odd[1], odd[2])
    elif y >= 2 and x >= 1:
        print("YES")
        print(even[0], even[1], odd[0])
    else:
        print("NO")