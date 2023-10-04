n, m = map(int, input().split())
c = 0
def rb2(a, b):
    global c
    if len(b) == n:
        print(a,b)
        c += 1
        return
    
    for i in range(1, m+1):
        if a[len(b)] == i or i in b:
            continue
        b.append(i)
        rb2(a,b)
        b.pop()


def rb(a):
    if (len(a) == n):
        rb2(a, [])
        return
    for i in range(1, m+1):
        if i in a:
            continue
        a.append(i)
        rb(a)
        a.pop()

rb([])

print(c)