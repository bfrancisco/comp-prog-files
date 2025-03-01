c = 0
for i in range(1, 98):
    for j in range(i+1, 98):
        if i+j == 98:
            c += 1

print(c)