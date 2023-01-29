pi = "3141592653589793238462643383279"
x = len(pi)
for _ in range(int(input())):
    ans = 0
    n = input()
    for i in range(min(x, len(n))):
        if n[i] != pi[i]:
            break
        ans += 1
    print(ans)
