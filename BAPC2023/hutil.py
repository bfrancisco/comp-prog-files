from math import lcm

h = 4000
w = 50
mx = 0
for i in range(1, h+1):
    for j in range(1, w+1):
        mx = max(mx, lcm(i, j))
        if (mx == 199950):
            print(i, j)
print(mx)