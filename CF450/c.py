n = int(input())
a = [int(i) for i in input().split()]

high = a[0]
inir = 1
for i in range(1, n):
    if a[i] > high:
        high = a[i]
        inir += 1
    else:
        break

if sorted(a) == a or sorted(a, reverse=True) == a:
    print(1)
    exit()
a = [0] + a + [n+1]

ans = -1
for i in range(1, n):
    if a[i] > a[i+1]:
        if a[i] > a[i-1] and a[i-1] > a[i+1]:
            print("one")
            ans = a[i+1]
        elif a[i] > a[i+2] and a[i+1] < a[i+2]:
            ans = a[i]
            print("two")
        else:
            ans = min(a[i], a[i+1], a[i+2])
            print("three", a[i], a[i+1])
        break

print(ans)