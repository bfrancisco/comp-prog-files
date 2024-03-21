for _ in range(int(input())):
    n = int(input())
    a = [abs(int(i)) for i in input().split()]
    print(sum(a))