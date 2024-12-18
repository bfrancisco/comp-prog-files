for _ in range(int(input())):
    n = int(input())

    if n%2==0:
        for i in range(n//2):
            print(i+1, i+1, end=' ')
        print()
    
    elif n >= 27:
        i = 1
        cnt = 0
        prev = 0
        while i <= n:
            if i == 1 or i == 10 or i == 26:
                print(1, end=' ')
            elif i == 23 or i == 27:
                print(10**6, end=' ')
            elif cnt == 0:
                print(i, end=' ')
                prev = i
                cnt = 1 - cnt
            elif cnt == 1:
                print(prev, end=' ')
                cnt = 1 - cnt
            i += 1
    
    else:
        print(-1)