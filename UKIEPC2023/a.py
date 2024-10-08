n, w = map(int, input().split())
a, b = w, -1

z = (1 if w + (n//2+1) <= 10**4 else -1)

for i in range(n//2):
    a += z
    b += 1
    print(a, b)

b = 501
for i in range(n//2+(n%2)):
    print(w, b)
    b += 1