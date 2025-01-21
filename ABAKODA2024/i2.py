n = int(input())
v = [int(i) for i in input().split()]

ans = 0
for bit in range(30):
    b1 = 0
    for i in range(n):
        b1 += (v[i] >> bit)&1
    b0 = n - b1

    con1 = b1 * (b0*(b0-1))//2
    con3 = b1 * (b1-1) * (b1-2) // 6

    ans += (con1 + con3) * (1 << bit)

print(ans*6)

# ans2 = (a[0] ^ a[1]) + (a[2] ^ a[3])
# ans2 += 2*(((a[0]^a[1]^a[2]) & (a[0]^a[1]^a[3])) + ((a[0]^a[2]^a[3]) & (a[1]^a[2]^a[3])))
# print(ans2*6)