a = []

for x in range(1, 10000):
    if (x%3 == 2 and x%5 == 3 and x%7 == 2):
        a.append(x)

print(a)

for i in range(0, len(a)-1, 2):
    print(a[i+1] - a[i])
