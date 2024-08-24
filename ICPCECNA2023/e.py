s = input()

for i in range(len(s)-1):
    if s[i] == s[i+1] and s[i] == 'O':
        print("INVALID")
        exit()

s = s[::-1]
base = 5
LMT = 2**47
while True:
    val = base
    good = True
    for c in s[1:]:
        if c == "E":
            val *= 2
        else:
            if ((val-1)%3):
                good = False
                break
            val = (val-1)//3

    base = base*4 + 1

    if val > LMT:
        print("INVALID")
        break
    
    if good:
        print(val)
        break