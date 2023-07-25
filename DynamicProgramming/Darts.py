MAX_N = 1000
MAX_DARTS = 4

n, m = [int(x) for x in input().split()]
S = [0, *(int(input()) for _ in range(n))]
S.sort()
# print(S)

opt = [[0 for darts_left in range(MAX_DARTS + 1)] for i in range(MAX_N + 1)]
for i in range(1, n + 1):
    for rem_darts in range(1, MAX_DARTS + 1):
        for prev_darts in range(rem_darts + 1):
            for prev_rows in range(1, i+1):

                total = opt[i-prev_rows][prev_darts] + (rem_darts - prev_darts) * S[i]
                if total <= m:
                    opt[i][rem_darts] = max(opt[i][rem_darts], total)
        
        # opt[i][rem_darts] = max(opt[i][rem_darts], opt[i][rem_darts-1])


for row in opt[:n+1]:
    print(*row)

print(opt[n][4])