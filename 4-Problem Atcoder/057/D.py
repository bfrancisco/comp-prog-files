from math import comb

n, a, b = map(int, input().split())

vec = [int(i) for i in input().split()]

vec.sort(reverse=True)

mxavg = sum(vec[:a]) / a
print(mxavg)

freq = 0
for x in vec:
    if x == vec[a-1]:
        freq += 1


if a == n or a==b or vec[a-1] != vec[a]:
    print(1)
    exit()
if vec[0] == vec[a-1]:
    ans = 0
    for i in range(a, min(b+1, freq+1)):
        ans += comb(freq, i)
    print(ans)
    exit()

least = sum([1 for i in vec[:a] if i == vec[a-1]])
print(comb(freq, least))