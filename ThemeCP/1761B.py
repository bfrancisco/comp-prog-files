for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    freq = {}
    for x in a:
        if x not in freq:
            freq[x] = 1
        else:
            freq[x] += 1
    
    if len(freq) == 2:
        print(n//2 + 1)
    else:
        print(n)
    
