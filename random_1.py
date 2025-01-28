a = [input() for i in range(256)]
b = [input() for i in range(256)]

for i in range(1, 257):
    if (a[i-1] != b[i-1]):
        print(i)