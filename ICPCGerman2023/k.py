from collections import deque

n, k = map(int, input().split())
a = deque(list(input()))

ans = 0
if (a[0] == "R"):
    print(ans)
    exit()
for _ in range(k):
    if (not a):
        ans += 1
        continue
    move = a[0]
    pas = 1
    p = 0
    for c in a:
        if c != move:
            pas = 0
            break
        if (move == "L"):
            move = "R"
        else:
            move = "L"
        p += 1
    for x in range(p):
        a.popleft()
    if (pas):
        ans += 1
print(ans)
