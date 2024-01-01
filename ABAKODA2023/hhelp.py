s = [2,0,0,0]
b = [0,5,8,9]
n = len(b)

m = -123
mn = 1000000

for i in range(-10, 11):
    news = [v+i for v in s]
    x = sum([abs(b[j]-news[j]) for j in range(n)])
    # print(x, i)
    if (x < mn):
        mn = x
        m = i

print(m, mn)