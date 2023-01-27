def gcd(x, y):
    while(y):
       x, y = y, x % y
    return abs(x)

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    b = [a[0]]
    # st = set(a[0])
    for i in range(1, n):
        b.append(b[-1] + a[i])
        # st.add(b[-1] + a[i])
        # st.add(a[i])
    
    mx = -1
    for i in range(n-1):
        x = b[i]
        y = b[n-1] - b[i]
        mx = max(mx, gcd(x, y))

    print(mx)

    
    