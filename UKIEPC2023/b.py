n, m, k = map(int, input().split())
a = [-1 for i in range(m+1)]
ans = [0 for i in range(m+1)]
for i in range(k):
    station, card = map(int, input().split())
    if a[card] == -1:
        a[card] = station
    else:
        ans[card] += (100 if station == a[card] else abs(station - a[card]))
        a[card] = -1

# print(a)
for card in range(1, m+1):
    if a[card] != -1:
        ans[card] += 100

print(*ans[1:])