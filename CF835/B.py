alpha = list('abcdefghijklmnopqrstuvwxyz')
for _ in range(int(input())):
    n = int(input())
    a = list(input())
    a.sort()
    print(alpha.index(a[-1]) + 1)

