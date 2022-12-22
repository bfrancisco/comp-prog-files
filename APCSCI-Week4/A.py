

n = int(input())

segments = []
for i in range(n):
    ia, ib = map(int, input().split())
    a, b = sorted([ia, ib])
    segments.append((a, b))

segments.sort()
out = []

# bruteforce: 
# if not intersecting, add the nail to out
# else, branch out to two scenarios:
    # 1. break and add the nail out
    # 2. recurse if intersecting


