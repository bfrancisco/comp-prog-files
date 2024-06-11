L, R = map(int, input().split())
MOD = 2019
ans = ((L%MOD) * ((L+1)%MOD)) % MOD
ans = (min((R-1)%MOD) * (R%MOD)) % MOD