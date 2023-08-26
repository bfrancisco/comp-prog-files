inp = []
for i in range(4):
    xx = input().split()
    for x in xx:
        inp.append(x)

s = []
for ii in range(52):
    s.append(inp[ii])

    i = 0
    while len(s)-1-i >= 3:
        print(len(s), -1-i, -4-i)
        if (s[-1-i][0] == s[-4-i][0]):
            s.pop()
            s.pop()
            s.pop()
            s.pop()
        elif (s[-1-i][1] == s[-4-i][1]):
            s.pop()
            last = s.pop()
            first = s.pop()
            s.pop()
            s.append(first)
            s.append(last)

        i += 1

print(len(s), end=" ")
print(*s)