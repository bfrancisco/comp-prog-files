for _ in range(int(input())):
    n = int(input())
    ans = []
    for i in range(n):
        s = input()
        ans.append(s.index('#') + 1)
    
    print(*ans[::-1])