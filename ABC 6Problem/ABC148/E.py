n = int(input())

ans = 0
div = 10
if n%2:
    print(0)
    exit()
while n >= div:
    ans += n//div
    div *= 5

print(ans)