def check(x, y):
    if 1 <= x and x <= h and 1 <= y and y <= w:
        return True
    return False

h, w, n = map(int, input().split())
ans = [0 for i in range(10)]
mn, mx = sorted([h,w])
ans[0] = (mn-2)**2 + ((mn-2) * (mx-mn))

#print(ans)
bank = set()
# not used lol
dirs = [
    (-1, -1), (-1, 0), (-1, 1),
    (0, -1), (0, 1),
    (1, -1), (1, 0), (1, 1),
]
for _ in range(n):
    a, b = map(int, input().split())

    for x in range(a-2, a+1):
        for y in range(b-2, b+1):
            if not check(x, y) or not check(x+2, y+2):
                continue
            initial = 0

            # check square
            for i in range(3):
                for j in range(3):
                    if (x+i, y+j) in bank:
                        initial += 1
            ans[initial] -= 1
            ans[initial + 1] += 1

    bank.add((a, b))

print(*ans, sep='\n')