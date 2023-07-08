a,b,c = map(int, input().split())
q, w = pow(a, c), pow(b, c)
if (q==w):
    print("=")
elif q > w:
    print(">")
else:
    print("<")