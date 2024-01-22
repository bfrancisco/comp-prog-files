def rec(a, k, c):
    global mn
    global mx
    global st

    if (a/k < 1):
        mn = min(mn, c)
        mx = max(mx, c)
        st.add(c)

    for v in range(1, a//k + 1):
        rec(a-v, k, c+1)    

a, k = map(int, input().split())
mn, mx = 1000000, -10000000
st = set()
rec(a, k, 0)

print(mn, mx)
print(st)

