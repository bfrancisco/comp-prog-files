n = int(input())

pat = [1, 0, 0, 1]
pi = 0
ans = []
for i in range(n, 0, -1):
    if pat[pi]:
        ans.append(i)
    pi = (pi+1) % 4

print(0 if n%4==0 or n%4==3 else 1)
print(len(ans), *ans)