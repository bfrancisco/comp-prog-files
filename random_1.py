d = 0
c = 0
for i in range(1, 7):
    for j in range(1, 7):
        for k in range(1, 7):
            if (i == 1 or j == 1 or k == 1):
                c += 1
            d += 1
print(c, d)