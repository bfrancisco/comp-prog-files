sc = {
    "Miss" : 0,
    "Bad" : 50,
    "Good" : 100,
    "Perfect" : 300,
}

ans = 0
n = int(input())
cons = 0
for _ in range(n):
    z = input()
    cons = (0 if z == "Miss" else cons+1)
    ans += sc[z]*cons
    # print(sc[z] * (1 + cons))
print(ans)