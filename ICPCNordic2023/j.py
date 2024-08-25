n, m = map(int, input().split())
a = [int(i) for i in input().split()]

a.sort()
if n <= m:
    print(a[-1])
    exit()

exc = m*2 - n
b = [e for e in a[-exc:]]
# print(b)
for i in range((n-exc)//2):
    b.append(a[i] + a[-exc-i-1])
# print(b)
print(max(b))