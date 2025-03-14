n, k = map(int, input().split())
a = [int(i)%k for i in input().split()]

freq = [0 for i in range(101)]
for e in a:
    freq[e] += 1

# print(a)

ans = freq[0] - (freq[0]%2)
for i in range(1, k//2 + (k%2)):
    ans += min(freq[i], freq[k-i])*2
if k%2==0:
    ans += (freq[k//2]) - (freq[k//2]%2)

print(ans)
