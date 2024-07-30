def palondrimize(sn):
    ni = int(sn)
    for i in range(1, 19):
        if (ni == 10**i):
            return ni-1

    isodd = (len(sn)%2 == 1)
    half = sn[:len(sn)//2 + (len(sn)%2)]
    lasti = len(half)-1
    while int(half[lasti]) == 0:
        lasti -= 1
    
    if (lasti == 0 and half[lasti] == '1'):
        pass
    else:
        half = half[:lasti] + str(int(half[lasti])-1) + half[lasti+1:]
    
    # print("Half:", half)
    if (isodd):
        palin = half[:-1] + half[-1] + half[-2::-1]
    else:
        palin = half + half[::-1]
    
    return int(palin)
    
def isPalindrome(z):
    s = str(z)
    return s == s[::-1]

n = input()
ans = []
while (int(n) >= 1000):
    highPal = palondrimize(n)
    # print(n, highPal)
    n = str(int(n) - highPal)
    ans.append(highPal)

done = False
n = int(n)
for i in range(n+1):
    if (not isPalindrome(i)):
        continue
    for j in range(n-i+1):
        k = n-i-j
        if (not isPalindrome(j) and not isPalindrome(k)):
            continue
        if (i+j+k == n):
            ans.append(i)
            ans.append(j)
            ans.append(k)
            done = True
            break
    if done:
        break

print(len(ans))
print(*ans, sep='\n')