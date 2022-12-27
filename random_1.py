a = [int(i) for i in input().split()]

for x in a[1:]:
    a[0] ^= x
print(a[0])