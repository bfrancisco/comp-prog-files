THRESH = 9

def parse(S):
    left = ""
    for i in range(len(S)):
        if S[i] == '.':
            continue
        if S[i] == 'e':
            break
        left += S[i]
    
    left = int(left) 

    right = ""
    for i in range(len(S)-1, -1, -1):
        if S[i] == 'e':
            break
        right += S[i]
    
    right = int(right[::-1]) - 9

    while left%10 == 0:
        left //= 10
        right += 1

    return left, right

def addsub(x, ex, y, ey, isAdd):
    if abs(ex-ey) > THRESH:
        if ex > ey:
            return x, ex
        return y, ey

    if ex <= ey:
        while ex < ey:
            ey -= 1
            y *= 10
    else:
        while ex > ey:
            ex -= 1
            x *= 10
    return x + isAdd*y, ex

def mul(x, ex, y, ey):
    v = x*y
    e = ex+ey
    return v, e

def div(x, ex, y, ey):
    v = x/y
    e = ex-ey

    while len(str(int(v))) <= THRESH and v != 0:
        v *= 10
        e -= 1
    
    return int(v), e

def comp(x, ex, y, ey):
    if abs(ex-ey) > THRESH:
        return "Incorrect"

    # print(x, ex)
    # print(y, ey)

    abso, absoe = addsub(x, ex, y, ey, -1)
    abso = abs(abso)
    rela, relae = div(abso, absoe, abs(y), ey)

    # print(abso, absoe)
    # print(rela, relae)
    # if (abs(-9-absoe) > 50 or abs(-9-relae) > 50):
    #     return "Correct"
    if  abso < 10**(-9-absoe) and rela < 10**(-9-relae):
        return "Correct"

    return "Incorrect"
    
inp = [input() for i in range(6)]

val = [-1 for i in range(6)]
exp = [-1 for i in range(6)]

for i in range(6):
    val[i], exp[i] = parse(inp[i])

# for i in range(6):
#     print(val[i], exp[i])
# print()

ans = [-1 for i in range(4)]
anse = [-1 for i in range(4)]

ans[0], anse[0] = addsub(val[0], exp[0], val[1], exp[1], 1)
ans[1], anse[1] = addsub(val[0], exp[0], val[1], exp[1], -1)
ans[2], anse[2] = mul(val[0], exp[0], val[1], exp[1])
ans[3], anse[3] = div(val[0], exp[0], val[1], exp[1])

for i in range(4):
    print(comp(ans[i], anse[i], val[i+2], exp[i+2]))