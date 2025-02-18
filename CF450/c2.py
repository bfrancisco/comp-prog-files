n = int(input())
A = [int(i) for i in input().split()]
high2 = [[0, 0] for i in range(n)] # high[0] > high[1]
contrib = [0 for i in range(n+1)]

high2[0][0] = A[0]
contrib[A[0]] = -1
for i in range(1, n):
    high2[i][0] = high2[i-1][0]
    high2[i][1] = high2[i-1][1]
    if A[i] > high2[i][0]:
        high2[i] = [A[i], high2[i][0]]
    elif A[i] > high2[i][1]:
        high2[i][1] = A[i]
    
    if high2[i][0] == A[i]:
        contrib[A[i]] = -1

print(contrib)

freq = [0 for i in range(n+1)]
for i in range(n):
    if A[i] in high2[i]:
        freq[high2[i][0]] += 1

for i in range(n):
    freq[high2[i][0]] = max(freq[A[i]]-1, 0)
    contrib[high2[i][0]] += freq[high2[i][0]]

mx = max(contrib)
ans = 0
for i in range(1, n+1):
    if mx == contrib[i]:
        ans = i
        break

print(*high2)
print(contrib)
print(ans)
    