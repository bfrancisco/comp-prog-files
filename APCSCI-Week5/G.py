n = int(input())
a = [int(i) for i in input().split()]

gr = [[] for i in range(n+1)]
for i in range(1, n+1):
    s = input()
    for j in range(1, n+1):
        if s[j-1] == '1':
            gr[i].append(j)

# for i in range(1, n+1):
#     print(i, gr[i])

for i in range(1, n+1):
    b = [a[i-1]]
    indeces = [i-1]
    for ind in gr[i]:
        b.append(a[ind-1])
        indeces.append(ind-1)
    b.sort()
    indeces.sort()

    for j in range(len(b)):
        a[indeces[j]] = b[j]

print(*a)