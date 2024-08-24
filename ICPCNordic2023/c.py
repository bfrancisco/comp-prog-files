db = {
    "I" : 1,
    "V" : 5,
    "X" : 10,
    "L" : 50,
    "C" : 100,
    "D" : 500,
    "M" : 1000,
    "Z" : 1001
}

for _ in range(int(input())):
    s = input()

    i = len(s)-1
    ans = 0
    while i >= 0:
        val = 0
        j = i-1
        while j >= 0:
            if db[s[i]] > db[s[j]]:
                val += db[s[j]]
            else:
                break
            j -= 1
        ans += db[s[i]] - val
        val = 0
        if db[s[i]] > db[s[j]]:
            i = j-1
        else:
            i = j
    
    print(ans)
