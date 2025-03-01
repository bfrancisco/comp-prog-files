n = int(input())
a = [int(i) for i in input().split()]

one = a.count(1)
two = a.count(2)

ans = one//3
for i in range(1, one+1):
    ans = max(ans, min(two, i) + (one-i)//3)
print(ans)