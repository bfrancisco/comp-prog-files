s = input()
a,b,c,d = int(s[0]), int(s[1]), int(s[2]), int(s[3])
ab = a*10 + b
cd = c*10 + d

if (1 <= ab and ab <= 12 and 1 <= cd and cd <= 12):
    print("AMBIGUOUS")
elif (1 <= ab and ab <= 12):
    print("MMYY")
elif (1 <= cd and cd <= 12):
    print("YYMM")
else:
    print("NA")