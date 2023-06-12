def ranom(ar, mx):
    ret = 0
    for i in range(len(ar)):
        v = pow(10, ar[i]-1)
        if ar[i] < mx[i]:
            ret -= v
        else:
            ret += v
    return ret


# ABCDEEDCBA
# ABCDEEECBA
# EBCDEEDCBA
# ABCDEEECBA
def solve():
    s = "EABCDEEDCBA"
    a = []
    for c in s:
        if c == 'A':
            a.append(1)
        elif c == 'B':
            a.append(2)
        elif c == 'C':
            a.append(3)
        elif c == 'D':
            a.append(4)
        else:
            a.append(5)
    
    # max per index
    mx = [0 for i in range(len(a))]
    tmp = -1
    for i in range(len(a)-1, -1, -1):
        tmp = max(tmp, a[i])
        mx[i] = tmp
    # print(a)
    # print(mx)
    print(ranom(a, mx))

for _ in range(1):
    solve()
