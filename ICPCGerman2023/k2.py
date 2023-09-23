n, k = map(int, input().split())
a = list(input())
memo = ["x" for i in range(n)]
ans = 0
for _ in range(k):
    move = "L"
    pas = 1
    for i in range(n):
        if (memo[i] != "x"):
            move = memo[i]
            continue
    
        if (move == a[i]):
            if (move == "L"):
                move = "R"
            else:
                move = "L"
            memo[i] = move
        else:
            pas = 0
            break
    if (pas):
        ans += 1
print(ans)