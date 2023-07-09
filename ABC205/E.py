w,b,k = map(int, input().split())
if (w > b + k):
    print(0)
    exit()
mod = 1000000007

fact = [0 for i in range(1000001)]
fact[1] = 1
for i in range(2, 1000001):
    fact[i] = i*fact[i-1]
    fact[i] %= mod

def C(n, r):
    print(n-r)

print(C(w+b, w) - C(w+b, b+k+1))
