def solve():
    n, k = map(int, input().split())
    h = [int(i) for i in input().split()]
    p = [int(i) for i in input().split()]

    a = []
    for i in range(n):
        a.append((p[i], h[i]))
    a.sort()

    #print(a)
    mnhealth = k
    i = 0
    while i < n:
        health = a[i][1]
        power = a[i][0]
        while health > mnhealth:
            k -= power
            mnhealth += k
            if k <= 0 and health > mnhealth:
                print("NO")
                return
        i += 1
    print("YES")
    
for _ in range(int(input())):
    solve()