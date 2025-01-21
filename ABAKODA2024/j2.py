def rec(n,a,b,c,ha,hb,hc,t):
    if ha <= 0 or hb <= 0 or hc <= 0:
        return 0.0
    if a == n or b == n or c == n:
        return 1.0

    st = (a,b,c,ha,hb,hc,t)
    if st in dp:
        return dp[st]
    
    abc = [a,b,c]
    habc = [ha,hb,hc]
    pi = t%3
    ret = 0.0

    for dice in range(2, 13):
        np = min(abc[pi] + dice, n)
        nh = habc[pi] - damage[np]

        if nh <= 0:
            continue
            
        np = abc[:]

n, sa, sb, sc = map(int, input().split())
damage = [int(i) for i in input().split()]

dice = [0 for i in range(13)]
for d1 in range(1, 7):
    for d2 in range(1, 7):
        dice[d1+d2] += 1/36

dp = {}

print(rec(0,0,0,sa,sb,sc,0))

