from math import lcm
a, b, k = map(int, input().split())
k *= 1000

A, B = 100000000000, -1
lc = lcm(a, b)
if (k % b == 0):
    A = k // b
else:
    for x in range(a, b):
        nlcm = lcm(b, x)
        if (nlcm > k): continue
        srt = [k-nlcm, nlcm]
        srt.sort()
        A = min(A, srt[1]//b + (srt[0]//x))

if (k % a == 0):
    B = k // a
else:
    for x in range(a+1, b+1):
        nlcm = lcm(a, x)
        if (nlcm > k): continue
        srt = [k-nlcm, nlcm]
        srt.sort()
        B = max(B, srt[1]//a + (srt[0]//x))

if (A == 100000000000 or B == -1):
    print("UNSATISFIABLE")
else:
    print(A, B)