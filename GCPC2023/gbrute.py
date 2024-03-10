n = int(input())
ans = [0 for i in range(10)]


for num in range(0, n+1):
    s = str(num)
    freq = [0 for i in range(10)]
    for d in s:
        freq[int(d)] += 1
    
    for i in range(10):
        ans[i] = max(ans[i], freq[i])

print(sum(ans))
