mod = 10**9 + 7
n = int(input())

c = 0
def rb(i, a):
    global c
    if i == n:
        s = set(a)
        if 0 in s and 9 in s:
            c += 1
            # print(a)
        return
    for x in range(10):
        a.append(x)
        rb(i+1, a)
        a.pop()

a = []
rb(0, a)
print(c)
