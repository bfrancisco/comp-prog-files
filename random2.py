a = 0
for i in range(4, 100):
    for j in range(4, 100):
        for k in range(4, 100):
            if i + j + k == 40:
                a += 1
print(a)