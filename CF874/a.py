for _ in range(int(input())):
    n = int(input())
    s = input()

    a = set()
    i = 0
    while i < len(s)-1:
        a.add(s[i:i+2])
        i += 1
        

    # print(a)
    print(len(a))