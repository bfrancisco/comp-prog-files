for _ in range(int(input())):
    m, s = map(int, input().split())
    a = [int(i) for i in input().split()]
    aset = set(a)
    a.sort()
    c = 0
    last = a[-1]
    for i in range(1, last+1):
        if i not in aset:
            c += i
    
    while c < s:
        last += 1
        c += last
    
    if c == s:
        print("YES")
    else:
        print("NO")
