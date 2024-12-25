def rec(s):
    if int(s)%33 == 0:
        return 1
    elif len(s) <= 2:
        return 0
        
    ret = 0
    for i in range(len(s + " ")-1):
        if s[i:i+1] == '33':
            ret = ret | rec(s[:i] + s[:i+2])
    
    return ret

for _ in range(int(input())):
    s = input()

    if int(s) < 33:
        print("NO")
        continue
    elif int(s)%33 == 0:
        print("YES")
        continue

    print("YES" if rec(s) else "NO")
    
