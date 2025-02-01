n = int(input())
x = int(input())
pat = [x]
nn = n
while nn and len(pat) < 6:
    if nn%2 and x != 2:
        x = (1 if x==0 else 0)
    elif nn%2==0 and x != 0:
        x = (2 if x==1 else 1)
    pat.append(x)
    nn -= 1
# print(x)
# print(pat)

print(pat[n%6])