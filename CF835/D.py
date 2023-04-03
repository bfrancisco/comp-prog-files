for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [float('inf')]
    for x in a:
        if not b or b[-1] != x:
            b.append(x)
    b.append(float('inf'))
    #print(b)
    c = 0
    for i in range(1,len(b)):
        if b[i-1] > b[i] and b[i] < b[i+1]:
            c+=1

    print("YES" if c==1 else "NO")