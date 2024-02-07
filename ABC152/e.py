from math import lcm

MOD = 1000000007

n = int(input())
a = [int(i) for i in input().split()]

LCM = 1
for e in a:
    LCM = lcm(LCM, e)

ans = 0
for e in a:
    ans += LCM//e
    ans %= MOD
print(ans)