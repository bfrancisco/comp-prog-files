s = input()
n = len(s)
brackets = []
st = set()
c = 0
prev = 0
for i in range(n):
    if s[i] == '(':
        c += 1
    else:
        c -= 1
    if c == 0:
        brackets.append(s[prev:i+1])
        st.add(s[prev:i+1])
        prev = i+1

if (len(st) == 1):
    print("no")
else:
    print(''.join(brackets[1 : len(brackets)]) + brackets[0])

