# inp = input().split()
inp = []
for i in range(4):
    xx = input().split()
    for x in xx:
        inp.append(x)

s = []
for ii in range(len(inp)):
    s.append(inp[ii])
    i = 1
    # print(*s)
    while len(s)-i >= 3:
        if (s[-i][0] == s[-3-i][0]):
            toputback = []
            for i in range(i-1):
                toputback.append(s.pop())
            s.pop()
            s.pop()
            s.pop()
            s.pop()
            for c in toputback[::-1]:
                s.append(c)
            i = 0

        elif (s[-i][1] == s[-3-i][1]):
            toputback = []
            for i in range(i-1):
                toputback.append(s.pop())
            s.pop()
            last = s.pop()
            first = s.pop()
            s.pop()
            s.append(first)
            s.append(last)
            for c in toputback[::-1]:
                s.append(c)
            i = 0
            

        i += 1

print(len(s), end=" ")
print(*s)