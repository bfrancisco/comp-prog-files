t = int(input())
typ = ""
conv = {
    "string" : "'string'",
    "boolean" : "true",
    "number" : "0",
}

for _ in range(t):
    inp = input().split()
    typ = inp[1]
    out = []
    while True:
        inp = input().split()
        if inp[0] == '};':
            break
        
        name = inp[0]
        data = inp[1][:-1]
        if data in conv:
            out.append(name + conv[data])
        else:
            assert(1 < 0)
    # print(out)
    outstr = '{' + ';'.join(out) + '}'
    # print(outstr)
    conv[typ] = outstr

print(conv[typ])
        

