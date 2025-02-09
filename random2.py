n = int(input())
a = []
for i in range(n):
    s = input()
    a.append(s[::-1])

a.sort()
for s in a:
    print(s[::-1], end='')
print()