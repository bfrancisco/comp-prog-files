for _ in range(int(input())):
    s = input()
    n = int(s)
    gud = False
    for i in range(len(s)-1):
        a = s[0:i+1]
        b = s[i+1:]
        if (a[0] == '0' or b[0] == '0'):
            continue

        aa = int(a)
        bb = int(b)

        if (aa < bb):
            print(aa, bb)
            gud = True
            break
    if not gud:
        print(-1)