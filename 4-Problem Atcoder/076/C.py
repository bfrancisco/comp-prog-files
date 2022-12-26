s = list(input())
t = input()
ts = len(t)
ss = len(s)
pas = False
index = -1
for i in range(0, ss - ts + 1):
    #print(s[i:i+ts])
    good = True
    for j in range(ts):
        if s[i+j] != '?' and s[i+j] != t[j]:
            good = False
            break
    if good:
        index = i
        pas = True
if not pas:
    print("UNRESTORABLE")
    exit()

for i in range(ts):
    s[index+i] = t[i]

for i in range(ss):
    if s[i] == '?':
        s[i] = 'a'

print(*s, sep='')