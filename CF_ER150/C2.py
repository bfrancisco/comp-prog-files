co = {
    0 : 1,
    1 : 10,
    2 : 100,
    3 : 1000,
    4 : 10000,
}

def ranom(s):
    n = len(s)
    ar = [0 for i in range(n)]
    mx = [0 for i in range(n)]

    for i in range(n):
        ar[i] = ord(s[i]) - 65
    
    tmp = -1
    for i in range(n-1, -1, -1):
        tmp = max(tmp, ar[i])
        mx[i] = tmp
    
    ret = 0
    for i in range(n):
        if ar[i] < mx[i]:
            ret -= co[ar[i]]
        else:
            ret += co[ar[i]]
    return ret


def solve():
    s = input()
    high = 'A'
    low = 'E'   
    for c in s:
        if ord(high) < ord(c):
            high = c
        if ord(low) > ord(c):
            low = c
    
    s2 = s
    for i in range(len(s2)):
        if s2[i] != 'E':
            s2 = s2[:i] + 'E' + s2[i+1:]
            break
    
    hi_ind = -1
    for i in range(len(s)-1, -1, -1):
        if s[i] == high:
            hi_ind = i
            break

    ans = max(ranom(s), ranom(s2))
    for c in "ABCD":
        s3 = s[:hi_ind] + c + s[hi_ind+1:]
        ans = max(ans, ranom(s3))

    s4 = s
    s4 = s[:hi_ind-1]

    print(ans)



for _ in range(int(input())):
    solve()