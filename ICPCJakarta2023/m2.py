n = int(input())
a = [int(i) for i in input().split()]

a.sort()

if a[n-1] >= 2*sum(a[0:n-1]):
    print(sum(a[0:n-1]))
else:
    print(sum(a)//3)