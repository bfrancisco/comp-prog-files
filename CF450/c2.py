n = int(input())
A = [int(i) for i in input().split()]
high2 = [[0, 0] for i in range(n)] # high[0] > high[1]

hs = set([A[0]])
high2[0][0], high2[0][1] = A[0], 0
for i in range(1, n):
    if A[i] >= high2[i-1][0]:
        high2[i][0] = A[i]
        high2[i][1] = high2[i-1][0]
    elif A[i] >= high2[i-1][1]:
        high2[i][0] = high2[i-1][0]
        high2[i][1] =  A[i]
    else:
        high2[i][0] = high2[i-1][0] 
        high2[i][1] = high2[i-1][1]

    if high2[i][0] > high2[i-1][0]:
        hs.add(A[i])
    
ad = [0 for i in range(n+1)]
for i in range(n):
    if A[i] != high2[i][0] and A[i] == high2[i][1]:
        ad[high2[i][0]] += 1


ans = [0 for i in range(n+1)]
for i in range(n):
    ans[A[i]] = ad[A[i]] + len(hs) - (1 if A[i] in hs else 0)

# print(*high2)
# print(*ad)
# print(ans)

print(max(1, ans.index(max(ans))))