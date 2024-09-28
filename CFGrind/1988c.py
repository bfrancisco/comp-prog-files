for _ in range(int(input())):
    n = int(input())
    inizero = set()
    for i in range(61):
        if not (n & (1 << i)):
            inizero.add(i)

    ans = [n]
    for i in range(61):
        if (1 << i) > n:
            break
        if i in inizero:
            continue
        
        if n - (1 << i) == 0:
            continue
        ans.append(n - (1 << i))
    
    print(len(ans))
    print(*(ans[::-1]))