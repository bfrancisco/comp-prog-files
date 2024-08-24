def good_hypen(hypens):
    sz = len(hypens)
    if 0 in hypens or 10 in hypens or (sz==3 and 9 not in hypens):
        return False
    if sz > 3:
        return False
    return True

def good_10(digits):
    m = 10
    s = 0
    for d in digits:
        s += m * d
        m -= 1
    
    # print(s)
    return s%11 == 0

def conv(digits):
    s = 9 + 3*7 + 8
    for i in range(9):
        if i%2==0:
            s += digits[i]*3
        else:
            s += digits[i]

    for z in range(10):
        if (s + z) % 10 == 0:
            return z

def good_13(digits):
    s = 9 + 3*7 + 8
    for i in range(10):
        if i%2==0:
            s += digits[i]*3
        else:
            s += digits[i]
    
    return s%10==0

for i in range(int(input())):
    s = input()
    digits = []
    hypens = set()

    d = 0
    Xisnotlast = False
    for c in s:
        if c == "-":
            hypens.add(d)
        elif c == "X":
            digits.append(10)
            d += 1
            if d != 10:
                Xisnotlast = True

        else:
            digits.append(int(c))
            d += 1
    
    consec = False
    for i in range(len(s)-1):
        if s[i] == s[i+1] and s[i] == "-":
            consec = True
            break


    
    if (Xisnotlast or consec or not good_hypen(hypens) or not good_10(digits) or len(digits) != 10):
        print("invalid")
        continue
    
    digits[9] = conv(digits)

    # assert(good_13(digits))

    print("978-", end='')
    print(s[:-1], end='')
    print(digits[9])