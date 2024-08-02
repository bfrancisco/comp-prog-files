MX = 500000

mxn, mxk = -1, -1
mx = 0
for n in range(1, 10001):
    for k in range(1, n+1):
        if (n*k > MX): continue
        if n*k*k > mx:
            mx = n*k*k
            mxn = n
            mxk = k

print(mxn, mxk)
print(mx)