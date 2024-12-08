for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [int(i) for i in input().split()]
    if sorted(a) == a or k > 1:
        print("YES")
    else:
        print("NO")