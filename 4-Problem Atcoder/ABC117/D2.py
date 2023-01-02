a = [int(i) for i in input().split()]

k = int(input())
mx = -1
val = -1
for i in range(k+1):
    x = 0
    for e in a:
        x += (e ^ i)
    if x > mx:
        mx = x
        val = i
    print("i:", i, " x:", x)