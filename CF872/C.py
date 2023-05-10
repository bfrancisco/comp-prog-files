from itertools import permutations

n, m = map(int, input().split())
q = [int(i) for i in input().split()]
ans = -1
for p in permutations([_ for _ in range(n)]):
    seats = [-1 for i in range(m+1)]
    left = m
    right = 1
    c = 0
    for i in range(n):
        if q[i] == -1 and left > 0:
            seats[left] = i+1
            left -= 1
            c+=1
        elif q[i] == -2 and right <= m:
            seats[right] = i+1
            right += 1
            c+=1
        elif seats[q[i]] != -1:
            seats[q[i]] = 0
            c+=1
    ans = max(ans, c)
print(ans)

